#pragma once

#include "greedyVisitor.h"
#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "models.h"

#include <queue>

using namespace antlr4;
using namespace antlrcpptest;

class palgo {

	class expr {
	public:
		std::string x,y;
		std::vector<int> c;
		bool val;
		expr(){}
	};

	class leaf {
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

	class dsu {
	private:
		std::vector<int> p,size;
		int numSets;
	public:
		dsu(int N):numSets(N){
			p.resize(numSets);
			for (int i=0;i<numSets;i++) p[i] = i;
			size.assign(numSets,1);
		}
		int findp(int i){ return (p[i] == i)?i:(p[i]=findp(p[i])); }
		bool isSame(int i,int j){ return findp(i) == findp(j); }
		void unionSet(int i,int j){
			if (!isSame(i,j)){
				int pi = findp(i);
				int pj = findp(j);
				if (size[pi] < size[pj]) std::swap(pj,pi);
				p[pj] = pi;
				size[pi] += size[pj];
			}
		}
	};

	class exprins{
	public:
		bool full;
		std::vector< std::vector<bool> > pos;
		exprins(int vs,bool f = false):full(f){
			pos.assign(3 , std::vector<bool>(vs,true) );
		}
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

	std::vector< std::vector<expr> > exprs;
	std::vector< std::vector<expr> > newexprs;
	std::shared_ptr<IModel> imodel;
	std::shared_ptr<node> tree;
	int modelvs;

	palgo (std::shared_ptr<IModel> m){
		imodel = m;
		modelvs = imodel->vectorSize();
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

	void Kosaraju(int no, std::vector< std::vector<int> >& gr, std::vector<bool> &vis, std::vector<int>& ans){

		vis[no] = true;
		for (int ne:gr[no]){
			if (!vis[ne]){
				Kosaraju(ne,gr,vis,ans);
			}
		}
		ans.push_back(no);

	}

	int fxidx(std::string x,std::vector<exprins> &instances,std::map<std::string,int> &idxs){
		int ans;
		if (idxs.find(x) == idxs.end()){
			ans = idxs[x] = instances.size();
			instances.emplace_back(modelvs);
		} else ans = idxs[x];
		return ans;
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
				if (ret) return true;

				newexprs[ctype].pop_back();
				return false;

			}

		} else {

			if (checkTree(tree)){

				// First, compress all of the variables with Kosaraju

				int idx = 0;
				std::map< std::string , int > mapidx;
				std::vector<std::string> rmap;
				std::vector< std::vector<int> > gr;
				std::vector< std::vector<int> > tgr;
				for (expr sub:newexprs[7]){

					int fi,si;

					if ( mapidx.find(sub.x) == mapidx.end() ){
						gr.push_back(std::vector<int>());
						rmap.push_back(sub.x);
						fi = mapidx[sub.x] = idx++;
					} else fi = mapidx[sub.x];

					if ( mapidx.find(sub.y) == mapidx.end() ){
						si = mapidx[sub.y] = idx++;
						rmap.push_back(sub.y);
						gr.push_back(std::vector<int>());
					} else si = mapidx[sub.y];

					gr[fi].push_back(si);
					tgr[si].push_back(fi);
				}

				std::vector<int> order;
				int numNodes = idx;
				std::vector<bool> visited(numNodes,false);

				for (int i=0;i<numNodes;i++){
					if (!visited[i]){
						std::vector<int> corder;
						Kosaraju(i,gr,visited,corder);
						order.insert(order.end(),corder.begin(),corder.end());
					}
				}

				std::vector< std::vector<int> > scc;
				visited.assign(numNodes,false);

				for (int i=numNodes-1;i>=0;i--){
					if ( !visited[ order[i] ] ){
						std::vector<int> cscc;
						Kosaraju(order[i] , tgr , visited , cscc);
						scc.push_back(cscc);
					}
				}

				// Compress full instances

				int sccn = scc.size();
				std::map< std::string , int > compressedidx;
				std::vector< std::vector<std::string> > rcmap(sccn);
				
				for (int i=0;i<sccn;i++){
					for (int j:scc[i]){
						compressedidx[ rmap[j] ] = i;
						rcmap[i].push_back(rmap[j]);
					}
				}

				std::vector< std::vector<int> > compgr(sccn);
				for (expr sub:newexprs[7]){
					int fi = compressedidx[sub.x];
					int si = compressedidx[sub.y];
					if (fi != si) compgr[fi].push_back(si);
				}

				visited.assign(sccn,false);
				dsu sccix(sccn);

				for (expr pos:newexprs[1]){
					if ( compressedidx.find(pos.x) != compressedidx.end() ){

						int cix = compressedidx[pos.x];

						if (visited[cix]) continue;
						visited[cix] = true;

						std::queue<int> bfs;
						bfs.push(cix);

						while (!bfs.empty()){

							int cno = bfs.front();

							for (int ne:gr[cno]){
								sccix.unionSet(cix,ne);

								if (!visited[ne]){
									visited[ne] = true;
									bfs.push(ne);
								}

							}

						}
					}
				}

				// take all variables from the sccix and start the rest of the algorithm

				std::map<std::string,int> finalidx;
				for (int i=0;i<sccn;i++){
					int cfidx = sccix.findp(i);
					for (int j=0;j<rcmap[i].size();j++){
						finalidx[ rcmap[i][j] ] = cfidx;
					}
				}

				std::vector<exprins> cvarins( sccn , exprins(modelvs) );

				//check if any variable requires pos(x) and ~pos(x)
				for (expr pose:newexprs[1]){
					int xidx = fxidx(pose.x,cvarins,finalidx);
					cvarins[xidx].full = true;
				}

				for (expr nege:newexprs[2]){
					int xidx = fxidx(nege.x,cvarins,finalidx);
					if (cvarins[xidx].full) return false;
				}

				// c <= x SUB3

				for (expr sub3:newexprs[3]){
					int xidx = fxidx(sub3.x,cvarins,finalidx);
					for (int i=0;i<modelvs;i++){
						if (sub3.c[i] != 2){
							if (cvarins[xidx].pos[ sub3.c[i] ][i]){
								cvarins[xidx].pos[2][i] = false;
								cvarins[xidx].pos[1 - sub3.c[i]][i] = false;
								if ( !( cvarins[xidx].pos[0][i] || cvarins[xidx].pos[1][i] || cvarins[xidx].pos[2][i] ) ) return false;
							} else return false;
						}
					}
				}

				// x <= c SUB5

				for (expr sub5:newexprs[3]){
					int xidx = fxidx(sub5.x,cvarins,finalidx);
					for (int i=0;i<modelvs;i++){
						if (sub5.c[i] != 0) cvarins[xidx].pos[0][i] = false;
						if (sub5.c[i] != 1) cvarins[xidx].pos[1][i] = false;
						if ( !( cvarins[xidx].pos[0][i] || cvarins[xidx].pos[1][i] || cvarins[xidx].pos[2][i] ) ) return false;
					}
				}

				return sub4(0,cvarins,finalidx);

			} else return false;

		}
	}

	bool sub4(int sidx , std::vector<exprins> &cvarins , std::map<std::string,int> &smap){
		if (sidx < newexprs[4].size()){

			int xidx = fxidx( newexprs[4][sidx].x , cvarins , smap );

			for (int i=0;i<modelvs;i++){
				if (newexprs[4][sidx].c[i] != 2){

					if ( cvarins[xidx].pos[ newexprs[4][sidx].c[i] ][i] ){
						cvarins[xidx].pos[ newexprs[4][sidx].c[i] ][i] = false;
						if (cvarins[xidx].pos[0][i] || cvarins[xidx].pos[1][i] || cvarins[xidx].pos[2][i]){
							if (sub4(sidx+1,cvarins,smap)) return true;
						}
						cvarins[xidx].pos[ newexprs[4][sidx].c[i] ][i] = true;
					} else {
						// Possible optimization, if there's one that's already wrong don't assign anything
						if (sub4(sidx+1,cvarins,smap)) return true;
					}
				}
			}

			return false;

		} else {

			return sub6(0,cvarins,smap);

		}
	}

	bool sub6(int sidx , std::vector<exprins> &cvarins , std::map<std::string,int> &smap){

		if (sidx < newexprs[6].size()){

			int xidx = fxidx( newexprs[6][sidx].x , cvarins , smap );

			for (int i=0;i<modelvs;i++){

				bool prev0 = cvarins[xidx].pos[0][i];
				bool prev1 = cvarins[xidx].pos[1][i];
				bool prev2 = cvarins[xidx].pos[2][i];

				cvarins[xidx].pos[2][i] = false;
				if (newexprs[6][sidx].c[i] == 0) cvarins[xidx].pos[0][i] = false;
				if (newexprs[6][sidx].c[i] == 1) cvarins[xidx].pos[1][i] = false;

				if (cvarins[xidx].pos[0][i] && cvarins[xidx].pos[1][i]){

					cvarins[xidx].pos[0][i] = false;
					if (sub6(sidx+1,cvarins,smap)) return true;
					cvarins[xidx].pos[0][i] = true;

					cvarins[xidx].pos[1][i] = false;
					if (sub6(sidx+1,cvarins,smap)) return true;
					cvarins[xidx].pos[1][i] = true;

				} else {
					if (cvarins[xidx].pos[0][i] || cvarins[xidx].pos[1][i]){
						if (sub6(sidx+1,cvarins,smap)) return true;
					}
				}

				cvarins[xidx].pos[0][i] = prev0;
				cvarins[xidx].pos[1][i] = prev1;
				cvarins[xidx].pos[2][i] = prev2;

			}

			return false;

		} else {

			return sub8(0,cvarins,smap);

		}
	}

	bool sub8(int sidx , std::vector<exprins> &cvarins , std::map<std::string,int> &smap){

		if (sidx < newexprs[8].size()){

			int xidx = fxidx( newexprs[8][sidx].x , cvarins , smap );
			int yidx = fxidx( newexprs[8][sidx].y , cvarins , smap );

			for (int i=0;i<modelvs;i++){

				bool befx[3];
				bool befy[3];
				for (int j=0;j<3;j++){
					befx[j] = cvarins[xidx].pos[j][i];
					befy[j] = cvarins[yidx].pos[j][i];
				}

				if (cvarins[xidx].pos[0][i] && (cvarins[yidx].pos[1][i] || cvarins[yidx].pos[2][i])){
					cvarins[xidx].pos[1][i] = false;
					cvarins[xidx].pos[2][i] = false;
					cvarins[yidx].pos[0][i] = false;
					if (sub8(sidx+1,cvarins,smap)) return true;
					cvarins[xidx].pos[1][i] = befx[1];
					cvarins[xidx].pos[2][i] = befx[2];
					cvarins[yidx].pos[0][i] = befy[0];
				}

				if (cvarins[xidx].pos[1][i] && (cvarins[yidx].pos[0][i] || cvarins[yidx].pos[2][i])){
					cvarins[xidx].pos[0][i] = false;
					cvarins[xidx].pos[2][i] = false;
					cvarins[yidx].pos[1][i] = false;
					if (sub8(sidx+1,cvarins,smap)) return true;
					cvarins[xidx].pos[0][i] = befx[0];
					cvarins[xidx].pos[2][i] = befx[2];
					cvarins[yidx].pos[1][i] = befy[1];
				}

			}

			return false;

		} else {

			return sub7(cvarins,smap);

		}
	}

	bool sub7(std::vector<exprins> &cvarins , std::map<std::string,int> &smap){

		int sub7s = newexprs[7].size();

		std::vector<int> xidx(sub7s);
		std::vector<int> yidx(sub7s);

		for (int i=0;i<sub7s;i++){
			xidx[i] = fxidx(newexprs[7][i].x,cvarins,smap);
			yidx[i] = fxidx(newexprs[7][i].y,cvarins,smap);
		}

		int cvis = cvarins.size();
		std::vector< std::vector<int> > gr(cvis);
		std::vector<int> inco(cvis,0);

		for (int i=0;i<sub7s;i++){
			gr[xidx[i]].push_back(yidx[i]);
			inco[yidx[i]]++;
		}

		std::queue<int> bfs;
		for (int i=0;i<cvis;i++){
			if (!inco[i]){
				bfs.push(i);
			}
		}

		while (!bfs.empty()){

			int cno = bfs.front();
			bfs.pop();

			for (int ne:gr[cno]){

				for (int i=0;i<modelvs;i++){

					if (!cvarins[cno].pos[2][i]){

						if (cvarins[cno].pos[0][i]){
							if (cvarins[ne].pos[0][i]){
								cvarins[ne].pos[1][i] = false;
								cvarins[ne].pos[2][i] = false;
							} else return false;
						} else {
							if (cvarins[ne].pos[1][i]){
								cvarins[ne].pos[0][i] = false;
								cvarins[ne].pos[2][i] = false;
							} else return false;
						}

					}
				}

				if (!(--inco[ne])) bfs.push(ne);
			}
		}

		return complete(cvarins,smap);

	}

	bool complete(std::vector<exprins> &cvarins , std::map<std::string,int> &smap){

		for (expr nege:newexprs[2]){
			int xidx = fxidx(nege.x,cvarins,smap);
			std::vector<bool> cins(modelvs);
			bool bottom = false;
			for (int i=0;i<modelvs;i++){
				if (cvarins[xidx].pos[2][i]){
					bottom = true;
					break;
				} else {
					cins[i] = cvarins[xidx].pos[1][i];
				}
			}
			if ( (!bottom) && (imodel->predict(cins))) return false;
		}

		for (expr pose:newexprs[1]){
			int xidx = fxidx(pose.x,cvarins,smap);
			std::vector<int> cins(modelvs);
			bool bottom = false;
			for (int i=0;i<modelvs;i++){
				if (cvarins[xidx].pos[0][i] || cvarins[xidx].pos[1][i]){
					if (cvarins[xidx].pos[0][i] && cvarins[xidx].pos[1][i]) cins[i] = 2;
					else if (cvarins[xidx].pos[0][i]) cins[i] = 0;
					else cins[i] = 1;
				} else {
					bottom = true;
					break;
				}
			}
			if (bottom || (!(imodel->complete(cins)))) return false;
		}

		return true;

	}

	void evaluate(invParser::InputContext* ctx){

		exprs.assign(9,std::vector< expr >());
		newexprs.assign(9,std::vector< expr >());

		tree = std::make_shared<node>();

		bool forall = false;

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