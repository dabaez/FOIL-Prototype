
// Generated from invParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "invParser.h"


namespace antlrcpptest {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by invParser.
 */
class  invParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by invParser.
   */
    virtual antlrcpp::Any visitInput(invParser::InputContext *context) = 0;

    virtual antlrcpp::Any visitQuans(invParser::QuansContext *context) = 0;

    virtual antlrcpp::Any visitQuan(invParser::QuanContext *context) = 0;

    virtual antlrcpp::Any visitGexists(invParser::GexistsContext *context) = 0;

    virtual antlrcpp::Any visitGforall(invParser::GforallContext *context) = 0;

    virtual antlrcpp::Any visitNoquans(invParser::NoquansContext *context) = 0;

    virtual antlrcpp::Any visitGor(invParser::GorContext *context) = 0;

    virtual antlrcpp::Any visitGand(invParser::GandContext *context) = 0;

    virtual antlrcpp::Any visitGno(invParser::GnoContext *context) = 0;

    virtual antlrcpp::Any visitGpos(invParser::GposContext *context) = 0;

    virtual antlrcpp::Any visitGsub(invParser::GsubContext *context) = 0;

    virtual antlrcpp::Any visitConstant(invParser::ConstantContext *context) = 0;


};

}  // namespace antlrcpptest
