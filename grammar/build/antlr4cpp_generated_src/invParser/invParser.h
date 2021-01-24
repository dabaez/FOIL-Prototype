
// Generated from invParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  invParser : public antlr4::Parser {
public:
  enum {
    COMMA = 1, VARIABLE = 2, BOOL = 3, OR = 4, AND = 5, NO = 6, POSITIVE = 7, 
    OPENP = 8, CLOSEP = 9, OPENB = 10, CLOSEB = 11, EXISTS = 12, FORALL = 13, 
    SUB = 14, WHITESPACE = 15
  };

  enum {
    RuleInput = 0, RuleQuans = 1, RuleQuan = 2, RuleGexists = 3, RuleGforall = 4, 
    RuleNoquans = 5, RuleGor = 6, RuleGand = 7, RuleGno = 8, RuleGpos = 9, 
    RuleGsub = 10, RuleCov = 11, RuleConstant = 12
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
  class GexistsContext;
  class GforallContext;
  class NoquansContext;
  class GorContext;
  class GandContext;
  class GnoContext;
  class GposContext;
  class GsubContext;
  class CovContext;
  class ConstantContext; 

  class  InputContext : public antlr4::ParserRuleContext {
  public:
    InputContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuansContext *quans();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InputContext* input();

  class  QuansContext : public antlr4::ParserRuleContext {
  public:
    QuansContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuanContext *quan();
    QuansContext *quans();
    NoquansContext *noquans();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuansContext* quans();

  class  QuanContext : public antlr4::ParserRuleContext {
  public:
    QuanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    GexistsContext *gexists();
    GforallContext *gforall();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuanContext* quan();

  class  GexistsContext : public antlr4::ParserRuleContext {
  public:
    GexistsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *VARIABLE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GexistsContext* gexists();

  class  GforallContext : public antlr4::ParserRuleContext {
  public:
    GforallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FORALL();
    antlr4::tree::TerminalNode *VARIABLE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GforallContext* gforall();

  class  NoquansContext : public antlr4::ParserRuleContext {
  public:
    NoquansContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GorContext *gor();
    GandContext *gand();
    GnoContext *gno();
    GposContext *gpos();
    GsubContext *gsub();


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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GnoContext* gno();

  class  GposContext : public antlr4::ParserRuleContext {
  public:
    GposContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POSITIVE();
    antlr4::tree::TerminalNode *OPENP();
    CovContext *cov();
    antlr4::tree::TerminalNode *CLOSEP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GposContext* gpos();

  class  GsubContext : public antlr4::ParserRuleContext {
  public:
    GsubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CovContext *> cov();
    CovContext* cov(size_t i);
    antlr4::tree::TerminalNode *SUB();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GsubContext* gsub();

  class  CovContext : public antlr4::ParserRuleContext {
  public:
    CovContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantContext *constant();
    antlr4::tree::TerminalNode *VARIABLE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CovContext* cov();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPENB();
    std::vector<antlr4::tree::TerminalNode *> BOOL();
    antlr4::tree::TerminalNode* BOOL(size_t i);
    antlr4::tree::TerminalNode *CLOSEB();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantContext* constant();


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
