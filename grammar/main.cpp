#include <iostream>

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"
#include "greedyVisitor.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

int main(int argc, const char* argv[]) {

	ifstream stream;
	stream.open(argv[1]);

	ANTLRInputStream input(stream);
	invLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	invParser parser(&tokens);
	invParser::InputContext* tree = parser.input();
	
	if ( gVisitor::evaluate(tree) ) cout<<"YES\n";
	else cout<<"NO\n";
	
	//cout<< tree->toStringTree(&parser) <<endl;
	
	return 0;
}
