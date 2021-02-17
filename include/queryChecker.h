#ifndef QUERYCHECKER_H
#define QUERYCHECKER_H

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "models.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

class qChecker{

	public:

	set<string> appear;
	shared_ptr<IModel> imodel;

	qChecker(shared_ptr<IModel> m){
		imodel = m;
	}

	bool check(invParser::InputContext* ctx){
		appear.clear();
		return check( ctx->gcount() );
	}
	
	bool check(invParser::GcountContext* ctx){
		if (ctx->VARIABLE()) appear.insert(ctx->VARIABLE()->getText());
		return check(ctx->quans());
	}

	bool check(invParser::QuansContext* ctx){

		if ( ctx -> quan() ){

			string var;
			if ( ctx->quan()->gexists() ){
				var = ctx->quan()->gexists()->VARIABLE()->getText();
			} else {
				var = ctx->quan()->gforall()->VARIABLE()->getText();
			}

			bool er = false;

			if ( appear.find(var) != appear.end() ){
				cout<<"Variable "<<var<<" defined more than once in the quantifiers"<<endl;
				er = true;
			} else {
				appear.insert(var);
			}

			return ( check( ctx->quans() ) || er );

		} else {
			return check( ctx -> noquans() );
		}
	}

	bool check(invParser::NoquansContext* ctx){
		if ( ctx -> gor() ){
			bool noq1, noq2;
			noq1 = check( ctx -> gor() -> noquans(0) );
			noq2 = check( ctx -> gor() -> noquans(1) );
			return  noq1 || noq2;
		}
		
		if ( ctx -> gand() ){
			bool noq1, noq2;
			noq1 = check( ctx -> gand() -> noquans(0) );
			noq2 = check( ctx -> gand() -> noquans(1) );
			return  noq1 || noq2;
		}
		
		if ( ctx -> gno() )
			return check( ctx -> gno() -> noquans() );
			
		if ( ctx -> gpos() )
			return check ( ctx -> gpos() -> cov() );
		
		if ( ctx -> gsub() ){
			bool noq1, noq2;
			noq1 = check( ctx -> gsub() -> cov(0) );
			noq2 = check( ctx -> gsub() -> cov(1) );
			return  noq1 || noq2;
		}
	}

	bool check(invParser::CovContext* ctx){

		if (ctx -> constant()){

			vector<int> cconst( ctx->constant()->BOOL().size() );

			for (int i=0;i<(ctx->constant()->BOOL().size());i++){
				if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "0" ) cconst[i] = 0;
				if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "1" ) cconst[i] = 1;
				if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "?" ) cconst[i] = 2;
			}

			if (!(imodel->checkVector(cconst))){
				cout<<"Model can't work with the constant "<<(ctx->constant()->getText())<<endl;
				return true;
			} else return false;

		} else {

			if ( appear.find(ctx->VARIABLE()->getText()) == appear.end() ){
				cout<<"Variable "<<(ctx->VARIABLE()->getText())<<" is free, not defined in the quantifiers"<<endl;
				return true;
			} else return false;

		}

	}


};

#endif
