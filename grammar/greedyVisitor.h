

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

namespace gVisitor{

bool evaluate(invParser::InputContext* ctx);
bool evaluate(invParser::QuansContext* ctx);
bool evaluate(invParser::NoquansContext* ctx);
bool evaluate(invParser::GposContext* ctx);
bool evaluate(invParser::GsubContext* ctx);
vector<int> val(invParser::CovContext* ctx);
vector<int> val(invParser::ConstantContext* ctx);

int perceptron_size;
vector<double> perceptron_w;
double perceptron_b;

map< string , vector<int> > vars;

long long fastpow(long long a,long long b){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a;
		b>>=1;
		a *= a;
	}
	return ans;
}

bool evaluate(invParser::InputContext* ctx){
    vars.clear();
    return evaluate( ctx->quans() );
}

bool evaluate(invParser::QuansContext* ctx){
    if ( ctx -> quan() ){
        if ( ctx->quan()->gexists() ){
			long long combs = fastpow( 3 , perceptron_size );
			vector<int> val(perceptron_size);
			for (long long ccomb=0;ccomb<combs;ccomb++){
				long long copy = ccomb;
				for (int i=0;i<perceptron_size;i++){
					val[i] = copy%3;
					copy/=3;
				}
				vars[ ctx->quan()->gexists()->VARIABLE()->getText() ] = val;
				if ( evaluate( ctx -> quans() ) ) return true;
			}
			return false;
        } else if ( ctx->quan()->gforall() ){
			long long combs = fastpow( 3 , perceptron_size );
			vector<int> val(perceptron_size);
			for (long long ccomb=0;ccomb<combs;ccomb++){
				long long copy = ccomb;
				for (int i=0;i<perceptron_size;i++){
					val[i] = copy%3;
					copy/=3;
				}
				vars[ ctx->quan()->gexists()->VARIABLE()->getText() ] = val;
				if ( ! evaluate( ctx -> quans() ) ) return false;
			}
			return true;
        }
    } else {
		return evaluate( ctx -> noquans() );
    }
}

bool evaluate(invParser::NoquansContext* ctx){
	if ( ctx -> gor() )
		return evaluate( ctx -> gor() -> noquans(0) ) || evaluate( ctx -> gor() -> noquans(1) );
	
	if ( ctx -> gand() )
		return evaluate( ctx -> gand() -> noquans(0) ) && evaluate( ctx -> gand() -> noquans(1) );
	
	if ( ctx -> gno() )
		return ! evaluate( ctx -> gno() -> noquans() );
		
	if ( ctx -> gpos() )
		return evaluate ( ctx -> gpos() );
	
	if ( ctx -> gsub() )
		return evaluate( ctx -> gsub() );
}

bool evaluate(invParser::GposContext* ctx){
	
	vector<int> value = val( ctx -> cov() );
	
	double ceval = 0;
	
	for (int i=0;i<perceptron_size;i++){
		if ( value[i] != 2 ) ceval += value[i] * perceptron_w[i];
		else if ( perceptron_w[i] > 0 ) ceval += perceptron_w[i];
	}
	
	return ceval >= -perceptron_b;
	
}

bool evaluate(invParser::GsubContext* ctx){
	
	 vector<int> left = val( ctx -> cov(0) );
	 vector<int> right = val( ctx -> cov(1) );
	 
	 for (int i=0;i<perceptron_size;i++){
		if (left[i] != right[i] && left[i] != 2) return false;
	 }
	 
	 return true;
	
}

vector<int> val(invParser::CovContext* ctx){
	if ( ctx -> constant() ){
		if ( ( ctx -> constant() -> BOOL().size() ) != perceptron_size ){
			//error de constante de tamano incorrecto
		} else {
			vector<int> ans( perceptron_size );
			for (int i=0;i<perceptron_size;i++){
				if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "0" ) ans[i] = 0;
				if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "1" ) ans[i] = 1;
				if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "?" ) ans[i] = 2;
			}
			return ans;
		}
	}
	if ( ctx -> VARIABLE() ){
		if ( vars.find( ctx -> VARIABLE() -> getText() ) == vars.end() ){
			//error de que nunca se declaro la variable
		} else {
			return vars[ ctx -> VARIABLE() -> getText() ];
		}
	}
}

}
