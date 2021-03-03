#pragma once

#include "greedyVisitor.h"
#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "models.h"
#include "fastpow.h"

using namespace antlr4;
using namespace antlrcpptest;

class gVisitor{

	public:
	
		gVisitor(std::shared_ptr<IModel> m);

		void evaluate(invParser::InputContext* ctx);
	
		void evaluate(invParser::GcountContext* ctx);

		bool evaluate(invParser::QuansContext* ctx);

		bool evaluate(invParser::NoquansContext* ctx);

		bool evaluate(invParser::GposContext* ctx);

		bool evaluate(invParser::GsubContext* ctx);

		std::vector<int> val(invParser::CovContext* ctx);
	
	private:
	
		std::map< std::string , std::vector<int> > vars;

		std::shared_ptr<IModel> imodel;

};
