#ifndef GREEDYVISITOR_H
#define GREEDYVISITOR_H

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "models.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

class gVisitor{

	public:
	
	map< string , vector<int> > vars;

	shared_ptr<IModel> imodel;
	
	gVisitor(shared_ptr<IModel> m){
		imodel = m;
	}

	long long fastpow(long long a,long long b){
		long long ans = 1;
		while (b){
			if (b&1) ans = ans*a;
			b>>=1;
			a *= a;
		}
		return ans;
	}

	void evaluate(invParser::InputContext* ctx){
		vars.clear();
		evaluate( ctx->gcount() );
	}
	
	void evaluate(invParser::GcountContext* ctx){
		if ( ctx->VARIABLE() ){
			long long ans = 0;
			long long combs = fastpow( 3 , imodel->vectorSize() );
			vector<int> val(imodel->vectorSize());
			for (long long ccomb=0;ccomb<combs;ccomb++){
				long long copy = ccomb;
				for (int i=0;i<(imodel->vectorSize());i++){
					val[i] = copy%3;
					copy/=3;
				}
				vars[ ctx->VARIABLE()->getText() ] = val;
				if ( evaluate( ctx -> quans() ) ) ans++;
			}
			std::cout<<ans<<std::endl;
		} else {
			if ( evaluate( ctx -> quans() ) ) std::cout<<"YES"<<std::endl;
			else std::cout<<"NO"<<std::endl;
		}
	}

	bool evaluate(invParser::QuansContext* ctx){
		if ( ctx -> quan() ){
			if ( ctx->quan()->gexists() ){
				long long combs = fastpow( 3 , imodel->vectorSize() );
				vector<int> val(imodel->vectorSize());
				for (long long ccomb=0;ccomb<combs;ccomb++){
					long long copy = ccomb;
					for (int i=0;i<(imodel->vectorSize());i++){
						val[i] = copy%3;
						copy/=3;
					}
					vars[ ctx->quan()->gexists()->VARIABLE()->getText() ] = val;
					if ( evaluate( ctx -> quans() ) ) return true;
				}
				return false;
			} else if ( ctx->quan()->gforall() ){
				long long combs = fastpow( 3 , imodel->vectorSize() );
				vector<int> val(imodel->vectorSize());
				for (long long ccomb=0;ccomb<combs;ccomb++){
					long long copy = ccomb;
					for (int i=0;i<(imodel->vectorSize());i++){
						val[i] = copy%3;
						copy/=3;
					}
					vars[ ctx->quan()->gforall()->VARIABLE()->getText() ] = val;
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
        for(int val : value) {
            if(val == 2) {
                    return false;
            }
        }
        vector<bool> boolValue(value.begin(), value.end());
		return imodel->predict(boolValue);
		
	}

	bool evaluate(invParser::GsubContext* ctx){
		
		 vector<int> left = val( ctx -> cov(0) );
		 vector<int> right = val( ctx -> cov(1) );
		 
		 if (left.size() != right.size()) return false;
		 
		 for (int i=0;i<left.size();i++){
			if (left[i] != right[i] && left[i] != 2) return false;
		 }
		 
		 return true;
		
	}

	vector<int> val(invParser::CovContext* ctx){
		
		if ( ctx -> constant() ){
			vector<int> ans( imodel->vectorSize() );
			for (int i=0;i<(imodel->vectorSize());i++){
				if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "0" ) ans[i] = 0;
				if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "1" ) ans[i] = 1;
				if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "?" ) ans[i] = 2;
			}
			return ans;
		}

		if ( ctx -> VARIABLE() ) return vars[ ctx -> VARIABLE() -> getText() ];
	}

};

#endif
