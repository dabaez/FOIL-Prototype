#pragma once

#include "greedyVisitor.h"
#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "models.h"

using namespace antlr4;
using namespace antlrcpptest;

class palgo {

	class expr{
	public:
		std::string x,y;
		std::vector<int> c;
		bool val;
		expr(){}
	};

	class leaf{
	public:
		int type;
		int idx;
		leaf(){}
	};

	class node {
	public:
		bool isor;
		bool isleaf;
		std::shared_ptr<node> left, right;
		std::shared_ptr<leaf> nodexp;
		node(){}
	};

	//0 : constant
	//1 : positive (x)
	//2 : ~positive(x)
	//3 : c <= x
	//4 : ~(c <= x)
	//5 : x <= c
	//6 : ~(x <= c)
	//7 : x <= y
	//8 : ~(x <= y)

	std::vector< std::vector< expr > > exprs;
	std::vector< std::vector< expr > > newexprs;
	std::shared_ptr<IModel> imodel;
	std::shared_ptr<node> tree;
	bool forall;

	palgo (std::shared_ptr<IModel> m){
		imodel = m;
	}

	bool checkTree(std::shared_ptr<node> cnode){
		if (cnode->isleaf){
			int ctype = cnode->nodexp->type;
			int cidx = cnode->nodexp->idx;
			return exprs[ctype][cidx].val;
		} else if (cnode -> isor){
			return checkTree(cnode->left) || checkTree(cnode->right);
		} else {
			return checkTree(cnode->left) && checkTree(cnode->right);
		}
	}

	bool tryall(int ctype, int cidx){
		if (ctype != 9){
			if (cidx == exprs[ctype].size()) return tryall(ctype+1,0);
			else {

				exprs[ctype][cidx].val = true;
				newexprs[ctype].push_back( exprs[ctype][cidx] );
				if (tryall(ctype,cidx+1)) return true;

				newexprs[ctype].pop_back();

				if (ctype%2) newexprs[ctype-1].push_back( exprs[ctype][cidx] );
				else newexprs[ctype+1].push_back( exprs[ctype][cidx] );
				exprs[ctype][cidx].val = false;

				bool ret = tryall(ctype,cidx+1);
				newexprs[ctype].pop_back();

				return ret;

			}
		} else {

			if (checkTree(tree)){

				//check if assignment is valid to itself
				return true;

			} else return false;

		}
	}

	void evaluate(invParser::InputContext* ctx){

		exprs.assign(9,std::vector< expr >());
		newexprs.assign(9,std::vector< expr >());

		tree = std::make_shared<node>();

		forall = false;

		if ( ctx -> gcount() ->quans() -> quan() ){
			if (ctx -> gcount() ->quans() -> quan() -> gforall()) forall = true;
		}

		invParser::QuansContext* ctxq = ctx->gcount()->quans();

		while ( ! (ctxq->noquans()) ) ctxq = ctxq->quans();

		buildt(ctxq->noquans(),tree,!forall);

		//tryall returns true if there is an instance that works
		//if forall is false, then we need tryall to return true
		//if forall is true, then we need tryall to return false (there's no instance that doesn't work)
		if (tryall(1,0) == (!forall)) std::cout<<"YES"<<std::endl;
		else std::cout<<"NO"<<std::endl;

	}

	void buildt(invParser::NoquansContext* ctx , std::shared_ptr<node> cnode , bool cnot){

		if ( ctx -> gor() ){
			cnode->isor = cnot;
			cnode->isleaf = false;
			cnode->left = std::make_shared<node>();
			cnode->right = std::make_shared<node>();
			buildt( ctx->gor() -> noquans(0) , cnode->left , cnot );
			buildt( ctx->gor() -> noquans(1) , cnode->right , cnot );
		}
		
		if ( ctx -> gand() ){
			cnode->isor = !cnot;
			cnode->isleaf = false;
			cnode->left = std::make_shared<node>();
			cnode->right = std::make_shared<node>();
			buildt( ctx->gand() -> noquans(0) , cnode->left , cnot );
			buildt( ctx->gand() -> noquans(1) , cnode->right , cnot );
		}
		
		if ( ctx -> gno() ){
			buildt( ctx -> gno() -> noquans() , cnode , !cnot );
		}
			
		if ( ctx -> gpos() ) return buildt ( ctx -> gpos() , cnode , cnot );
		
		if ( ctx -> gsub() ) return buildt ( ctx -> gsub() , cnode , cnot);

	}

	void buildt(invParser::GposContext* ctx , std::shared_ptr<node> cnode , bool cnot){

		cnode->isleaf = true;
		cnode->nodexp = std::make_shared<leaf>();

		if ( ctx -> cov() -> constant() ){

			cnode->nodexp->type = 0;
			int cidx = exprs[0].size();
			cnode->nodexp->idx = cidx;
			exprs[0].emplace_back();
			std::vector<int> ccons = vecconst( ctx -> cov() -> constant() );

			if ( std::find( ccons.begin() , ccons.end() , 2 ) == ccons.end() ){

				std::vector<bool> cconsbool (ccons.begin(),ccons.end());
				exprs[0][cidx].val = imodel->predict(cconsbool);

			} else { 

				exprs[0][cidx].val = false;

			}

			if (cnot) exprs[0][cidx].val = !exprs[0][cidx].val;

		} else {

			int ctype;

			if (cnot) ctype = 1;
			else ctype = 2;

			cnode->nodexp->type = ctype;

			int cidx = exprs[cnode->nodexp->type].size();

			cnode->nodexp->idx = cidx;

			exprs[ctype].emplace_back();

			exprs[ctype][cidx].x  = ctx -> cov() -> VARIABLE() -> getText();

		}


	}

	void buildt(invParser::GsubContext* ctx , std::shared_ptr<node> cnode , bool cnot){

		cnode -> isleaf = true;
		cnode -> nodexp = std::make_shared<leaf>();
		int ctype, cidx;

		if (ctx->cov(0)->constant() && ctx->cov(1)->constant()) ctype = 0;

		if (ctx->cov(0)->constant() && ctx->cov(1)->VARIABLE()){
			if (cnot) ctype = 3;
			else ctype = 4;
		}

		if (ctx->cov(0)->VARIABLE() && ctx->cov(1)->constant()){
			if (cnot) ctype = 5;
			else ctype = 6;
		}

		if (ctx->cov(0)->VARIABLE() && ctx->cov(1)->VARIABLE()){
			if (cnot) ctype = 7;
			else ctype = 8;
		}

		cnode -> nodexp -> type = ctype;
		cidx = exprs[ctype].size();
		cnode -> nodexp -> idx = cidx;
		exprs[ctype].emplace_back();

		if (ctype == 0){

			bool cval = true;
			std::vector<int> c1 = vecconst( ctx->cov(0)->constant() );
			std::vector<int> c2 = vecconst( ctx->cov(1)->constant() );
			for (int i=0;i<c1.size() && cval;i++){
				if (c1[i] != 2 && c1[i] != c2[i]) cval = false;
			}
			exprs[ctype][cidx].val = cval;

		}

		if (ctype == 3 || ctype == 4){

			exprs[ctype][cidx].c = vecconst(ctx->cov(0)->constant());
			exprs[ctype][cidx].x = ctx -> cov(1) -> VARIABLE() -> getText();

		}

		if (ctype == 5 || ctype == 6){

			exprs[ctype][cidx].x = ctx -> cov(0) -> VARIABLE() -> getText();
			exprs[ctype][cidx].c = vecconst(ctx->cov(1)->constant());

		}

		if (ctype == 7 || ctype == 8){

			exprs[ctype][cidx].x = ctx -> cov(0) -> VARIABLE() -> getText();
			exprs[ctype][cidx].y = ctx -> cov(1) -> VARIABLE() -> getText();

		}



	}

	std::vector<int> vecconst (invParser::ConstantContext* ctx){

		std::vector<int> ans( ctx -> BOOL().size() );
		for (int i=0;i<(ctx -> BOOL().size());i++){
			if ( ( ctx -> BOOL(i) -> getText() ) == "0" ) ans[i] = 0;
			if ( ( ctx -> BOOL(i) -> getText() ) == "1" ) ans[i] = 1;
			if ( ( ctx -> BOOL(i) -> getText() ) == "?" ) ans[i] = 2;
		}
		return ans;

	}

};