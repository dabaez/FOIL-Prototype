#include <iostream>

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

int main(int argc, const char* argv[]) {
  ifstream stream;
  stream.open(argv[1]);
  ANTLRInputStream input(stream);
  invLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  
  tokens.fill();
  for (auto token: tokens.getTokens()){
	  cout<< token->toString() <<endl;
  }
  
  invParser parser(&tokens);
  tree::ParseTree* tree = parser.input();
  
  cout<< tree->toStringTree(&parser) <<endl<<endl;

  return 0;
}
