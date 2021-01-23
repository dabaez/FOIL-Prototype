

#include "antlr4-runtime.h"
#include "invLexer.h"
#include "invParser.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

namespace gVisitor{

bool evaluate(invParser::InputContext* ctx){
    return true;
}

}
