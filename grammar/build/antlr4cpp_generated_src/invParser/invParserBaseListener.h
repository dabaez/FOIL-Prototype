
// Generated from invParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "invParserListener.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of invParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  invParserBaseListener : public invParserListener {
public:

  virtual void enterInput(invParser::InputContext * /*ctx*/) override { }
  virtual void exitInput(invParser::InputContext * /*ctx*/) override { }

  virtual void enterQuans(invParser::QuansContext * /*ctx*/) override { }
  virtual void exitQuans(invParser::QuansContext * /*ctx*/) override { }

  virtual void enterQuan(invParser::QuanContext * /*ctx*/) override { }
  virtual void exitQuan(invParser::QuanContext * /*ctx*/) override { }

  virtual void enterNoquans(invParser::NoquansContext * /*ctx*/) override { }
  virtual void exitNoquans(invParser::NoquansContext * /*ctx*/) override { }

  virtual void enterGor(invParser::GorContext * /*ctx*/) override { }
  virtual void exitGor(invParser::GorContext * /*ctx*/) override { }

  virtual void enterGand(invParser::GandContext * /*ctx*/) override { }
  virtual void exitGand(invParser::GandContext * /*ctx*/) override { }

  virtual void enterGno(invParser::GnoContext * /*ctx*/) override { }
  virtual void exitGno(invParser::GnoContext * /*ctx*/) override { }

  virtual void enterGpos(invParser::GposContext * /*ctx*/) override { }
  virtual void exitGpos(invParser::GposContext * /*ctx*/) override { }

  virtual void enterGsub(invParser::GsubContext * /*ctx*/) override { }
  virtual void exitGsub(invParser::GsubContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace antlrcpptest
