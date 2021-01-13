
// Generated from invParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  invParser : public antlr4::Parser {
public:
  enum {
    COMMA = 1, VARIABLE = 2, CONSTANT = 3, OR = 4, AND = 5, NO = 6, POSITIVE = 7, 
    OPENP = 8, CLOSEP = 9, EXISTS = 10, FORALL = 11, SUB = 12, WHITESPACE = 13
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

   
  };

  InputContext* input();

  class  QuansContext : public antlr4::ParserRuleContext {
  public:
    QuansContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuanContext *quan();
    QuansContext *quans();

   
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
