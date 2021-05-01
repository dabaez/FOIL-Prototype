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

public:

	palgo (std::shared_ptr<IModel> m);

	void evaluate(invParser::InputContext* ctx);

private:

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

	class change{
	public:
		int xidx, pos, idx;
		change(int xidx,int pos,int idx):xidx(xidx),pos(pos),idx(idx){}
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

	bool checkTree(std::shared_ptr<node> cnode);

	void Kosaraju(int no, std::vector< std::vector<int> >& gr, std::vector<bool> &vis, std::vector<int>& ans);

	int fxidx(std::string x,std::vector<exprins> &instances,std::map<std::string,int> &idxs);

	bool tryall(int ctype, int cidx);

	bool sub4(int sidx , std::vector<exprins> &cvarins , std::map<std::string,int> &smap);

	bool sub6(int sidx , std::vector<exprins> &cvarins , std::map<std::string,int> &smap);

	bool sub8(int sidx , std::vector<exprins> &cvarins , std::map<std::string,int> &smap);

	bool sub7(std::vector<exprins> &cvarins , std::map<std::string,int> &smap);

	bool complete(std::vector<exprins> &cvarins , std::map<std::string,int> &smap);

	void buildt(invParser::NoquansContext* ctx , std::shared_ptr<node> cnode , bool cnot);

	void buildt(invParser::GposContext* ctx , std::shared_ptr<node> cnode , bool cnot);

	void buildt(invParser::GsubContext* ctx , std::shared_ptr<node> cnode , bool cnot);

	std::vector<int> vecconst (invParser::ConstantContext* ctx);

};