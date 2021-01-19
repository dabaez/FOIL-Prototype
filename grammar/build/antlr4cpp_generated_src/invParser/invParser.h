
// Generated from invParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  invParser : public antlr4::Parser {
public:
  enum {
    COMMA = 1, VARIABLE = 2, CONSTANT = 3, BOOL = 4, OR = 5, AND = 6, NO = 7, 
    POSITIVE = 8, OPENP = 9, CLOSEP = 10, EXISTS = 11, FORALL = 12, SUB = 13, 
    WHITESPACE = 14
  };

  enum {
    RuleInput = 0, RuleQuans = 1, RuleQuan = 2, RuleNoquans = 3, RuleGor = 4, 
    RuleGand = 5, RuleGno = 6, RuleGpos = 7, RuleGsub = 8
  };

  explicit invParser(antlr4::TokenStream *input);
  ~invParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class InputContext;
  class QuansContext;
  class QuanContext;
  class NoquansContext;
  class GorContext;
  class GandContext;
  class GnoContext;
  class GposContext;
  class GsubContext; 

  class  InputContext : public antlr4::ParserRuleContext {
  public:
    InputContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuansContext *quans();
    NoquansContext *noquans();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InputContext* input();

  class  QuansContext : public antlr4::ParserRuleContext {
  public:
    QuansContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuanContext *quan();
    QuansContext *quans();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuansContext* quans();

  class  QuanContext : public antlr4::ParserRuleContext {
  public:
    QuanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLE();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *FORALL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuanContext* quan();

  class  NoquansContext : public antlr4::ParserRuleContext {
  public:
    NoquansContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GorContext *gor();
    GandContext *gand();
    GnoContext *gno();
    GposContext *gpos();
    GsubContext *gsub();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NoquansContext* noquans();

  class  GorContext : public antlr4::ParserRuleContext {
  public:
    GorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OPENP();
    antlr4::tree::TerminalNode* OPENP(size_t i);
    std::vector<NoquansContext *> noquans();
    NoquansContext* noquans(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CLOSEP();
    antlr4::tree::TerminalNode* CLOSEP(size_t i);
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GorContext* gor();

  class  GandContext : public antlr4::ParserRuleContext {
  public:
    GandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OPENP();
    antlr4::tree::TerminalNode* OPENP(size_t i);
    std::vector<NoquansContext *> noquans();
    NoquansContext* noquans(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CLOSEP();
    antlr4::tree::TerminalNode* CLOSEP(size_t i);
    antlr4::tree::TerminalNode *AND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GandContext* gand();

  class  GnoContext : public antlr4::ParserRuleContext {
  public:
    GnoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NO();
    antlr4::tree::TerminalNode *OPENP();
    NoquansContext *noquans();
    antlr4::tree::TerminalNode *CLOSEP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GnoContext* gno();

  class  GposContext : public antlr4::ParserRuleContext {
  public:
    GposContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POSITIVE();
    antlr4::tree::TerminalNode *OPENP();
    antlr4::tree::TerminalNode *CLOSEP();
    antlr4::tree::TerminalNode *CONSTANT();
    antlr4::tree::TerminalNode *VARIABLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GposContext* gpos();

  class  GsubContext : public antlr4::ParserRuleContext {
  public:
    GsubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUB();
    std::vector<antlr4::tree::TerminalNode *> CONSTANT();
    antlr4::tree::TerminalNode* CONSTANT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VARIABLE();
    antlr4::tree::TerminalNode* VARIABLE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GsubContext* gsub();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpptest
