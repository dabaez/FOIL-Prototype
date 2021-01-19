
// Generated from invParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "invParser.h"


namespace antlrcpptest {

/**
 * This interface defines an abstract listener for a parse tree produced by invParser.
 */
class  invParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterInput(invParser::InputContext *ctx) = 0;
  virtual void exitInput(invParser::InputContext *ctx) = 0;

  virtual void enterQuans(invParser::QuansContext *ctx) = 0;
  virtual void exitQuans(invParser::QuansContext *ctx) = 0;

  virtual void enterQuan(invParser::QuanContext *ctx) = 0;
  virtual void exitQuan(invParser::QuanContext *ctx) = 0;

  virtual void enterNoquans(invParser::NoquansContext *ctx) = 0;
  virtual void exitNoquans(invParser::NoquansContext *ctx) = 0;

  virtual void enterGor(invParser::GorContext *ctx) = 0;
  virtual void exitGor(invParser::GorContext *ctx) = 0;

  virtual void enterGand(invParser::GandContext *ctx) = 0;
  virtual void exitGand(invParser::GandContext *ctx) = 0;

  virtual void enterGno(invParser::GnoContext *ctx) = 0;
  virtual void exitGno(invParser::GnoContext *ctx) = 0;

  virtual void enterGpos(invParser::GposContext *ctx) = 0;
  virtual void exitGpos(invParser::GposContext *ctx) = 0;

  virtual void enterGsub(invParser::GsubContext *ctx) = 0;
  virtual void exitGsub(invParser::GsubContext *ctx) = 0;


};

}  // namespace antlrcpptest
