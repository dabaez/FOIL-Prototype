#include <iostream>

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "greedyVisitor.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

int main(int argc, const char* argv[]) {

	ifstream ptn("perceptron.txt");
	ptn>>gVisitor::perceptron_size;
	
	gVisitor::perceptron_w.resize(gVisitor::perceptron_size);
	for (int i=0;i<gVisitor::perceptron_size;i++) ptn>>gVisitor::perceptron_w[i];
	
	ptn>>gVisitor::perceptron_b;
	
	string s;
	while ( getline(cin,s) , s != "" ){
		
		stringstream stream(s);
		
		ANTLRInputStream input(stream);
		invLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		invParser parser(&tokens);
		invParser::InputContext* ctx = parser.input();
		
		if ( gVisitor::evaluate(ctx) ) cout<<"YES\n";
		else cout<<"NO\n";
		
		//cout<< ctx->toStringTree(&parser) <<endl;
		
	}
	
	return 0;
}
