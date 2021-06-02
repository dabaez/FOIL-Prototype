#include "queryChecker2.h"

qChecker2::qChecker2(std::shared_ptr<IModel> m){
	imodel = m;
}

bool qChecker2::check(invParser::InputContext* ctx){
	appear.clear();
	return check( ctx->gcount() );
}

bool qChecker2::check(invParser::GcountContext* ctx){
	if (ctx->VARIABLE()){
		std::cout<<"Count operation isn't available for this algorithm"<<std::endl;
		appear.insert(ctx->VARIABLE()->getText());
		check(ctx->quans());
		return true;
	} return check(ctx->quans());
}

bool qChecker2::check(invParser::QuansContext* ctx){

	if ( ctx -> quan() ){

		std::string var;
		if ( ctx->quan()->gexists() ){
			var = ctx->quan()->gexists()->VARIABLE()->getText();
		} else {
			var = ctx->quan()->gforall()->VARIABLE()->getText();
		}

		bool er = false;

		if ( appear.find(var) != appear.end() ){
			std::cout<<"Variable "<<var<<" defined more than once in the quantifiers"<<std::endl;
			er = true;
		} else {
			appear.insert(var);
		}

		if ( ctx -> quans() -> quan() ){
			if ( ctx -> quan() -> gexists() && ctx -> quans() -> quan() -> gforall() ){
				std::cout<<"All quantifiers need to be the same, but "<<ctx->quan()->gexists()->VARIABLE()->getText()<<" and "<<ctx -> quans() -> quan() -> gforall()->VARIABLE()->getText()<<" have different quantifiers"<<std::endl;
				er = true;
			}

			if ( ctx -> quan() -> gforall() && ctx -> quans() -> quan() -> gexists() ){
				std::cout<<"All quantifiers need to be the same, but "<<ctx->quan()->gforall()->VARIABLE()->getText()<<" and "<<ctx -> quans() -> quan() -> gexists()->VARIABLE()->getText()<<" have different quantifiers"<<std::endl;
				er = true;
			}

		}

		return ( check( ctx->quans() ) || er );

	} else {
		return check( ctx -> noquans() );
	}
}

bool qChecker2::check(invParser::NoquansContext* ctx){
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

	if ( ctx -> gfull() ){
		std::cout<<"Can't use FULL in this version"<<std::endl;
		check ( ctx -> gfull() -> cov() );
		return true;
	}
	
	if ( ctx -> gsub() ){
		bool noq1, noq2;
		noq1 = check( ctx -> gsub() -> cov(0) );
		noq2 = check( ctx -> gsub() -> cov(1) );
		return  noq1 || noq2;
	}
}

bool qChecker2::check(invParser::CovContext* ctx){

	if (ctx -> constant()){

		std::vector<int> cconst( ctx->constant()->BOOL().size() );

		for (int i=0;i<(ctx->constant()->BOOL().size());i++){
			if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "0" ) cconst[i] = 0;
			if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "1" ) cconst[i] = 1;
			if ( ( ctx -> constant() -> BOOL(i) -> getText() ) == "?" ) cconst[i] = 2;
		}

		if (!(imodel->checkVector(cconst))){
			std::cout<<"Model can't work with the constant "<<(ctx->constant()->getText())<<std::endl;
			return true;
		} else return false;

	} else {

		if ( appear.find(ctx->VARIABLE()->getText()) == appear.end() ){
			std::cout<<"Variable "<<(ctx->VARIABLE()->getText())<<" is free, not defined in the quantifiers"<<std::endl;
			return true;
		} else return false;

	}

}
