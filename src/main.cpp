#include <iostream>
#include <getopt.h>

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "models.h"
#include "perceptron.h"
#include "DecisionTree.h"
#include "greedyVisitor.h"
#include "queryChecker.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

class ParserErrorListener:public BaseErrorListener{
public:
	virtual void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                           const std::string &msg, std::exception_ptr e) override {
		cout<<"Error parsing query: ";
		cout<<msg<<endl;
		throw -1;
	}
};

int main(int argc, char** argv) {

	shared_ptr<IModel> mod;

	bool defmod=false,deffile=false;
	string sfile;

	const option long_opts[] = {
		{"model",required_argument,0,'m'},
		{"file",required_argument,0,'f'}
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
				else {
					cout<<string(optarg)<<" is not a valid model type"<<endl;
					return 0;
				}
				break;
		}
	}

	if (defmod){
		if (deffile){
			mod -> readFromFile(sfile);
			cout<<"File loaded from "<<sfile<<'\n';
		} else {
			cout<<"File not specified, model will be read from console"<<endl;
			mod -> readFromConsole();
		}
	} else {
		cout<<"Model not defined, needs to be defined as a command line argument as --model=perceptron"<<endl;
		return 0;
	}
	
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
		
	}
	
	return 0;
}
