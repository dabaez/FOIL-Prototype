#pragma once

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "models.h"

using namespace antlr4;
using namespace antlrcpptest;

class qChecker2{

	public:

		qChecker2(std::shared_ptr<IModel> m);

		bool check(invParser::InputContext* ctx);
		
		bool check(invParser::GcountContext* ctx);

		bool check(invParser::QuansContext* ctx);

		bool check(invParser::NoquansContext* ctx);

		bool check(invParser::CovContext* ctx);
		
	private:
	
		std::set<std::string> appear;
		
		std::shared_ptr<IModel> imodel;


};
