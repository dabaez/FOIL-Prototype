#include "errorListener.h"

void ParserErrorListener::syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                           const std::string &msg, std::exception_ptr e) {
	std::cout<<"Error parsing query: ";
	std::cout<<msg<<std::endl;
	throw -1;
}
