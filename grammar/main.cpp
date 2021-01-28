#include <iostream>

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "greedyVisitor.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

int main(int argc, const char* argv[]) {
	
	shared_ptr<IModel> p (new Perceptron);
	p -> readFromFile("perceptron.txt");
	
	gVisitor visitor(p);
	
	string s;
	while ( getline(cin,s) , s != "" ){
		
		stringstream stream(s);
		
		ANTLRInputStream input(stream);
		invLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		invParser parser(&tokens);
		invParser::InputContext* ctx = parser.input();
		
		if ( visitor.evaluate(ctx) ) cout<<"YES\n";
		else cout<<"NO\n";

		//tree::ParseTree *tree = parser.input();
		//cout<< tree->toStringTree(&parser) <<endl;
		
		//EXISTS x, P(x)
		//EXISTS x, ( [ ?,? ,?, 1] <= x ) ^ ( P ( x ) )
	}
	
	return 0;
}
