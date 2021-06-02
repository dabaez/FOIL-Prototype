#include <iostream>
#include <getopt.h>

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "models.h"
#include "perceptron.h"
#include "DecisionTree.h"
#include "AFBDD.h"
#include "greedyVisitor.h"
#include "queryChecker.h"
#include "paperalgo.h"
#include "queryChecker2.h"
#include "paperalgofull.h"
#include "queryChecker3.h"
#include "errorListener.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

int main(int argc, char** argv) {

	shared_ptr<IModel> mod;

	bool defmod=false,deffile=false,one=false;
	int defversion = 1;
	string sfile;

	const option long_opts[] = {
		{"model",required_argument,0,'m'},
		{"file",required_argument,0,'f'},
		{"one",no_argument,0,'o'},
		{"v",required_argument,0,'v'}
	};
	
	while (true){

		const auto opt = getopt_long(argc,argv,"",long_opts,0);

		if (opt == -1) break;

		switch (opt){
			case 'f':
				deffile = true;
				sfile = string(optarg);
				break;
			case 'm':
				defmod = true;
				if ( string(optarg) == "perceptron" ) mod = make_shared<Perceptron>();
                else if( string(optarg) == "dt" ) mod = make_shared<DecisionTree>();
                else if( string(optarg) == "afbdd") mod = make_shared<AFBDD>();
				else {
					cout<<string(optarg)<<" is not a valid model type"<<endl;
					return 0;
				}
				break;
			case 'o':
				one = true;
				break;
			case 'v':
				if (string(optarg) == "1") defversion = 1;
				else if (string(optarg) == "2") defversion = 2;
				else if (string(optarg) == "3") defversion = 3;
				else {
					cout<<string(optarg)<<" is not a valid version"<<endl;
					return 0;
				}
				break;
		}
	}

	if (defmod){
		if (deffile){
			mod -> readFromFile(sfile);
			if (!one) cout<<"File loaded from "<<sfile<<'\n';
			if (!one) cout<<"Number of features = "<<mod->vectorSize()<<endl;
		} else {
			cout<<"File not specified, model will be read from console"<<endl;
			mod -> readFromConsole();
		}
	} else {
		cout<<"Model not defined, needs to be defined as a command line argument as --model=perceptron"<<endl;
		return 0;
	}

	if (defversion == 1){

		if (!one) cout<<"Using naive algorithm"<<endl;
	
		gVisitor visitor(mod);
		qChecker checker(mod);
		
		string s;
		
		while ( getline(cin,s) , s != "" ){
			
			try{
			
				ParserErrorListener parserErrorListener;
				
				stringstream stream(s);
				ANTLRInputStream input(stream);
				invLexer lexer(&input);
				
				lexer.removeErrorListeners();
				lexer.addErrorListener(&parserErrorListener);
				
				CommonTokenStream tokens(&lexer);
				invParser parser(&tokens);
				
				parser.removeErrorListeners();
				parser.addErrorListener(&parserErrorListener);
			
				invParser::InputContext* ctx = parser.input();
				if ( checker.check(ctx) ) continue;
				visitor.evaluate(ctx);
			} catch (...){
				continue;
			}

			if (one) break;
			
		}

	} else if (defversion == 2){

		if (!one) cout<<"Using efficient algorithm without full"<<endl;

		palgo visitor(mod);
		qChecker2 checker(mod);
		
		string s;
		
		while ( getline(cin,s) , s != "" ){
			
			try{
			
				ParserErrorListener parserErrorListener;
				
				stringstream stream(s);
				ANTLRInputStream input(stream);
				invLexer lexer(&input);
				
				lexer.removeErrorListeners();
				lexer.addErrorListener(&parserErrorListener);
				
				CommonTokenStream tokens(&lexer);
				invParser parser(&tokens);
				
				parser.removeErrorListeners();
				parser.addErrorListener(&parserErrorListener);
			
				invParser::InputContext* ctx = parser.input();
				if ( checker.check(ctx) ) continue;
				visitor.evaluate(ctx);
			} catch (...){
				continue;
			}

			if (one) break;
			
		}

	} else {

		if (!one) cout<<"Using efficient algorithm with full"<<endl;

		palgof visitor(mod);
		qChecker3 checker(mod);
		
		string s;
		
		while ( getline(cin,s) , s != "" ){
			
			try{
			
				ParserErrorListener parserErrorListener;
				
				stringstream stream(s);
				ANTLRInputStream input(stream);
				invLexer lexer(&input);
				
				lexer.removeErrorListeners();
				lexer.addErrorListener(&parserErrorListener);
				
				CommonTokenStream tokens(&lexer);
				invParser parser(&tokens);
				
				parser.removeErrorListeners();
				parser.addErrorListener(&parserErrorListener);
			
				invParser::InputContext* ctx = parser.input();
				if ( checker.check(ctx) ) continue;
				visitor.evaluate(ctx);
			} catch (...){
				continue;
			}

			if (one) break;
			
		}

	}
	
	return 0;
}
