
// Generated from invParser.g4 by ANTLR 4.9.1


#include "invParserVisitor.h"

#include "invParser.h"


using namespace antlrcpp;
using namespace antlrcpptest;
using namespace antlr4;

invParser::invParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

invParser::~invParser() {
  delete _interpreter;
}

std::string invParser::getGrammarFileName() const {
  return "invParser.g4";
}

const std::vector<std::string>& invParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& invParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- InputContext ------------------------------------------------------------------

invParser::InputContext::InputContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

invParser::QuansContext* invParser::InputContext::quans() {
  return getRuleContext<invParser::QuansContext>(0);
}


size_t invParser::InputContext::getRuleIndex() const {
  return invParser::RuleInput;
}


antlrcpp::Any invParser::InputContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitInput(this);
  else
    return visitor->visitChildren(this);
}

invParser::InputContext* invParser::input() {
  InputContext *_localctx = _tracker.createInstance<InputContext>(_ctx, getState());
  enterRule(_localctx, 0, invParser::RuleInput);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    quans();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuansContext ------------------------------------------------------------------

invParser::QuansContext::QuansContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

invParser::QuanContext* invParser::QuansContext::quan() {
  return getRuleContext<invParser::QuanContext>(0);
}

invParser::QuansContext* invParser::QuansContext::quans() {
  return getRuleContext<invParser::QuansContext>(0);
}

invParser::NoquansContext* invParser::QuansContext::noquans() {
  return getRuleContext<invParser::NoquansContext>(0);
}


size_t invParser::QuansContext::getRuleIndex() const {
  return invParser::RuleQuans;
}


antlrcpp::Any invParser::QuansContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitQuans(this);
  else
    return visitor->visitChildren(this);
}

invParser::QuansContext* invParser::quans() {
  QuansContext *_localctx = _tracker.createInstance<QuansContext>(_ctx, getState());
  enterRule(_localctx, 2, invParser::RuleQuans);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(32);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case invParser::EXISTS:
      case invParser::FORALL: {
        enterOuterAlt(_localctx, 1);
        setState(28);
        quan();
        setState(29);
        quans();
        break;
      }

      case invParser::VARIABLE:
      case invParser::NO:
      case invParser::POSITIVE:
      case invParser::OPENP:
      case invParser::OPENB: {
        enterOuterAlt(_localctx, 2);
        setState(31);
        noquans();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuanContext ------------------------------------------------------------------

invParser::QuanContext::QuanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* invParser::QuanContext::COMMA() {
  return getToken(invParser::COMMA, 0);
}

invParser::GexistsContext* invParser::QuanContext::gexists() {
  return getRuleContext<invParser::GexistsContext>(0);
}

invParser::GforallContext* invParser::QuanContext::gforall() {
  return getRuleContext<invParser::GforallContext>(0);
}


size_t invParser::QuanContext::getRuleIndex() const {
  return invParser::RuleQuan;
}


antlrcpp::Any invParser::QuanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitQuan(this);
  else
    return visitor->visitChildren(this);
}

invParser::QuanContext* invParser::quan() {
  QuanContext *_localctx = _tracker.createInstance<QuanContext>(_ctx, getState());
  enterRule(_localctx, 4, invParser::RuleQuan);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case invParser::EXISTS: {
        setState(34);
        gexists();
        break;
      }

      case invParser::FORALL: {
        setState(35);
        gforall();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(38);
    match(invParser::COMMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GexistsContext ------------------------------------------------------------------

invParser::GexistsContext::GexistsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* invParser::GexistsContext::EXISTS() {
  return getToken(invParser::EXISTS, 0);
}

tree::TerminalNode* invParser::GexistsContext::VARIABLE() {
  return getToken(invParser::VARIABLE, 0);
}


size_t invParser::GexistsContext::getRuleIndex() const {
  return invParser::RuleGexists;
}


antlrcpp::Any invParser::GexistsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitGexists(this);
  else
    return visitor->visitChildren(this);
}

invParser::GexistsContext* invParser::gexists() {
  GexistsContext *_localctx = _tracker.createInstance<GexistsContext>(_ctx, getState());
  enterRule(_localctx, 6, invParser::RuleGexists);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(40);
    match(invParser::EXISTS);
    setState(41);
    match(invParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GforallContext ------------------------------------------------------------------

invParser::GforallContext::GforallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* invParser::GforallContext::FORALL() {
  return getToken(invParser::FORALL, 0);
}

tree::TerminalNode* invParser::GforallContext::VARIABLE() {
  return getToken(invParser::VARIABLE, 0);
}


size_t invParser::GforallContext::getRuleIndex() const {
  return invParser::RuleGforall;
}


antlrcpp::Any invParser::GforallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitGforall(this);
  else
    return visitor->visitChildren(this);
}

invParser::GforallContext* invParser::gforall() {
  GforallContext *_localctx = _tracker.createInstance<GforallContext>(_ctx, getState());
  enterRule(_localctx, 8, invParser::RuleGforall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    match(invParser::FORALL);
    setState(44);
    match(invParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoquansContext ------------------------------------------------------------------

invParser::NoquansContext::NoquansContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

invParser::GorContext* invParser::NoquansContext::gor() {
  return getRuleContext<invParser::GorContext>(0);
}

invParser::GandContext* invParser::NoquansContext::gand() {
  return getRuleContext<invParser::GandContext>(0);
}

invParser::GnoContext* invParser::NoquansContext::gno() {
  return getRuleContext<invParser::GnoContext>(0);
}

invParser::GposContext* invParser::NoquansContext::gpos() {
  return getRuleContext<invParser::GposContext>(0);
}

invParser::GsubContext* invParser::NoquansContext::gsub() {
  return getRuleContext<invParser::GsubContext>(0);
}


size_t invParser::NoquansContext::getRuleIndex() const {
  return invParser::RuleNoquans;
}


antlrcpp::Any invParser::NoquansContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitNoquans(this);
  else
    return visitor->visitChildren(this);
}

invParser::NoquansContext* invParser::noquans() {
  NoquansContext *_localctx = _tracker.createInstance<NoquansContext>(_ctx, getState());
  enterRule(_localctx, 10, invParser::RuleNoquans);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(46);
      gor();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(47);
      gand();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(48);
      gno();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(49);
      gpos();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(50);
      gsub();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GorContext ------------------------------------------------------------------

invParser::GorContext::GorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> invParser::GorContext::OPENP() {
  return getTokens(invParser::OPENP);
}

tree::TerminalNode* invParser::GorContext::OPENP(size_t i) {
  return getToken(invParser::OPENP, i);
}

std::vector<invParser::NoquansContext *> invParser::GorContext::noquans() {
  return getRuleContexts<invParser::NoquansContext>();
}

invParser::NoquansContext* invParser::GorContext::noquans(size_t i) {
  return getRuleContext<invParser::NoquansContext>(i);
}

std::vector<tree::TerminalNode *> invParser::GorContext::CLOSEP() {
  return getTokens(invParser::CLOSEP);
}

tree::TerminalNode* invParser::GorContext::CLOSEP(size_t i) {
  return getToken(invParser::CLOSEP, i);
}

tree::TerminalNode* invParser::GorContext::OR() {
  return getToken(invParser::OR, 0);
}


size_t invParser::GorContext::getRuleIndex() const {
  return invParser::RuleGor;
}


antlrcpp::Any invParser::GorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitGor(this);
  else
    return visitor->visitChildren(this);
}

invParser::GorContext* invParser::gor() {
  GorContext *_localctx = _tracker.createInstance<GorContext>(_ctx, getState());
  enterRule(_localctx, 12, invParser::RuleGor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(invParser::OPENP);
    setState(54);
    noquans();
    setState(55);
    match(invParser::CLOSEP);
    setState(56);
    match(invParser::OR);
    setState(57);
    match(invParser::OPENP);
    setState(58);
    noquans();
    setState(59);
    match(invParser::CLOSEP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GandContext ------------------------------------------------------------------

invParser::GandContext::GandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> invParser::GandContext::OPENP() {
  return getTokens(invParser::OPENP);
}

tree::TerminalNode* invParser::GandContext::OPENP(size_t i) {
  return getToken(invParser::OPENP, i);
}

std::vector<invParser::NoquansContext *> invParser::GandContext::noquans() {
  return getRuleContexts<invParser::NoquansContext>();
}

invParser::NoquansContext* invParser::GandContext::noquans(size_t i) {
  return getRuleContext<invParser::NoquansContext>(i);
}

std::vector<tree::TerminalNode *> invParser::GandContext::CLOSEP() {
  return getTokens(invParser::CLOSEP);
}

tree::TerminalNode* invParser::GandContext::CLOSEP(size_t i) {
  return getToken(invParser::CLOSEP, i);
}

tree::TerminalNode* invParser::GandContext::AND() {
  return getToken(invParser::AND, 0);
}


size_t invParser::GandContext::getRuleIndex() const {
  return invParser::RuleGand;
}


antlrcpp::Any invParser::GandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitGand(this);
  else
    return visitor->visitChildren(this);
}

invParser::GandContext* invParser::gand() {
  GandContext *_localctx = _tracker.createInstance<GandContext>(_ctx, getState());
  enterRule(_localctx, 14, invParser::RuleGand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(invParser::OPENP);
    setState(62);
    noquans();
    setState(63);
    match(invParser::CLOSEP);
    setState(64);
    match(invParser::AND);
    setState(65);
    match(invParser::OPENP);
    setState(66);
    noquans();
    setState(67);
    match(invParser::CLOSEP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GnoContext ------------------------------------------------------------------

invParser::GnoContext::GnoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* invParser::GnoContext::NO() {
  return getToken(invParser::NO, 0);
}

tree::TerminalNode* invParser::GnoContext::OPENP() {
  return getToken(invParser::OPENP, 0);
}

invParser::NoquansContext* invParser::GnoContext::noquans() {
  return getRuleContext<invParser::NoquansContext>(0);
}

tree::TerminalNode* invParser::GnoContext::CLOSEP() {
  return getToken(invParser::CLOSEP, 0);
}


size_t invParser::GnoContext::getRuleIndex() const {
  return invParser::RuleGno;
}


antlrcpp::Any invParser::GnoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitGno(this);
  else
    return visitor->visitChildren(this);
}

invParser::GnoContext* invParser::gno() {
  GnoContext *_localctx = _tracker.createInstance<GnoContext>(_ctx, getState());
  enterRule(_localctx, 16, invParser::RuleGno);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    match(invParser::NO);
    setState(70);
    match(invParser::OPENP);
    setState(71);
    noquans();
    setState(72);
    match(invParser::CLOSEP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GposContext ------------------------------------------------------------------

invParser::GposContext::GposContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* invParser::GposContext::POSITIVE() {
  return getToken(invParser::POSITIVE, 0);
}

tree::TerminalNode* invParser::GposContext::OPENP() {
  return getToken(invParser::OPENP, 0);
}

invParser::CovContext* invParser::GposContext::cov() {
  return getRuleContext<invParser::CovContext>(0);
}

tree::TerminalNode* invParser::GposContext::CLOSEP() {
  return getToken(invParser::CLOSEP, 0);
}


size_t invParser::GposContext::getRuleIndex() const {
  return invParser::RuleGpos;
}


antlrcpp::Any invParser::GposContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitGpos(this);
  else
    return visitor->visitChildren(this);
}

invParser::GposContext* invParser::gpos() {
  GposContext *_localctx = _tracker.createInstance<GposContext>(_ctx, getState());
  enterRule(_localctx, 18, invParser::RuleGpos);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    match(invParser::POSITIVE);
    setState(75);
    match(invParser::OPENP);
    setState(76);
    cov();
    setState(77);
    match(invParser::CLOSEP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GsubContext ------------------------------------------------------------------

invParser::GsubContext::GsubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<invParser::CovContext *> invParser::GsubContext::cov() {
  return getRuleContexts<invParser::CovContext>();
}

invParser::CovContext* invParser::GsubContext::cov(size_t i) {
  return getRuleContext<invParser::CovContext>(i);
}

tree::TerminalNode* invParser::GsubContext::SUB() {
  return getToken(invParser::SUB, 0);
}


size_t invParser::GsubContext::getRuleIndex() const {
  return invParser::RuleGsub;
}


antlrcpp::Any invParser::GsubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitGsub(this);
  else
    return visitor->visitChildren(this);
}

invParser::GsubContext* invParser::gsub() {
  GsubContext *_localctx = _tracker.createInstance<GsubContext>(_ctx, getState());
  enterRule(_localctx, 20, invParser::RuleGsub);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    cov();
    setState(80);
    match(invParser::SUB);
    setState(81);
    cov();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CovContext ------------------------------------------------------------------

invParser::CovContext::CovContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

invParser::ConstantContext* invParser::CovContext::constant() {
  return getRuleContext<invParser::ConstantContext>(0);
}

tree::TerminalNode* invParser::CovContext::VARIABLE() {
  return getToken(invParser::VARIABLE, 0);
}


size_t invParser::CovContext::getRuleIndex() const {
  return invParser::RuleCov;
}


antlrcpp::Any invParser::CovContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitCov(this);
  else
    return visitor->visitChildren(this);
}

invParser::CovContext* invParser::cov() {
  CovContext *_localctx = _tracker.createInstance<CovContext>(_ctx, getState());
  enterRule(_localctx, 22, invParser::RuleCov);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case invParser::OPENB: {
        setState(83);
        constant();
        break;
      }

      case invParser::VARIABLE: {
        setState(84);
        match(invParser::VARIABLE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

invParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* invParser::ConstantContext::OPENB() {
  return getToken(invParser::OPENB, 0);
}

std::vector<tree::TerminalNode *> invParser::ConstantContext::BOOL() {
  return getTokens(invParser::BOOL);
}

tree::TerminalNode* invParser::ConstantContext::BOOL(size_t i) {
  return getToken(invParser::BOOL, i);
}

tree::TerminalNode* invParser::ConstantContext::CLOSEB() {
  return getToken(invParser::CLOSEB, 0);
}

std::vector<tree::TerminalNode *> invParser::ConstantContext::COMMA() {
  return getTokens(invParser::COMMA);
}

tree::TerminalNode* invParser::ConstantContext::COMMA(size_t i) {
  return getToken(invParser::COMMA, i);
}


size_t invParser::ConstantContext::getRuleIndex() const {
  return invParser::RuleConstant;
}


antlrcpp::Any invParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<invParserVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

invParser::ConstantContext* invParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 24, invParser::RuleConstant);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(invParser::OPENB);
    setState(88);
    match(invParser::BOOL);
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == invParser::COMMA) {
      setState(89);
      match(invParser::COMMA);
      setState(90);
      match(invParser::BOOL);
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(96);
    match(invParser::CLOSEB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> invParser::_decisionToDFA;
atn::PredictionContextCache invParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN invParser::_atn;
std::vector<uint16_t> invParser::_serializedATN;

std::vector<std::string> invParser::_ruleNames = {
  "input", "quans", "quan", "gexists", "gforall", "noquans", "gor", "gand", 
  "gno", "gpos", "gsub", "cov", "constant"
};

std::vector<std::string> invParser::_literalNames = {
  "", "','", "", "", "'V'", "'^'", "'~'", "'P'", "'('", "')'", "'['", "']'", 
  "'EXISTS'", "'FORALL'", "'<='", "' '"
};

std::vector<std::string> invParser::_symbolicNames = {
  "", "COMMA", "VARIABLE", "BOOL", "OR", "AND", "NO", "POSITIVE", "OPENP", 
  "CLOSEP", "OPENB", "CLOSEB", "EXISTS", "FORALL", "SUB", "WHITESPACE"
};

dfa::Vocabulary invParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> invParser::_tokenNames;

invParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x11, 0x65, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x23, 
    0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x27, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x36, 0xa, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x58, 0xa, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x5e, 0xa, 0xe, 0xc, 0xe, 
    0xe, 0xe, 0x61, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x2, 0x2, 0xf, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x2, 0x2, 0x2, 0x5f, 0x2, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x4, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x26, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x35, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x10, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x1d, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x1f, 0x5, 0x6, 0x4, 0x2, 0x1f, 0x20, 0x5, 0x4, 0x3, 0x2, 
    0x20, 0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 0x23, 0x5, 0xc, 0x7, 0x2, 0x22, 
    0x1e, 0x3, 0x2, 0x2, 0x2, 0x22, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x27, 0x5, 0x8, 0x5, 0x2, 0x25, 0x27, 0x5, 
    0xa, 0x6, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0x3, 0x2, 
    0x2, 0x29, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0xe, 0x2, 0x2, 
    0x2b, 0x2c, 0x7, 0x4, 0x2, 0x2, 0x2c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2d, 
    0x2e, 0x7, 0xf, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x4, 0x2, 0x2, 0x2f, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x36, 0x5, 0xe, 0x8, 0x2, 0x31, 0x36, 0x5, 
    0x10, 0x9, 0x2, 0x32, 0x36, 0x5, 0x12, 0xa, 0x2, 0x33, 0x36, 0x5, 0x14, 
    0xb, 0x2, 0x34, 0x36, 0x5, 0x16, 0xc, 0x2, 0x35, 0x30, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x31, 0x3, 0x2, 0x2, 0x2, 0x35, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0xa, 0x2, 0x2, 0x38, 0x39, 
    0x5, 0xc, 0x7, 0x2, 0x39, 0x3a, 0x7, 0xb, 0x2, 0x2, 0x3a, 0x3b, 0x7, 
    0x6, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0xa, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0xc, 
    0x7, 0x2, 0x3d, 0x3e, 0x7, 0xb, 0x2, 0x2, 0x3e, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x40, 0x7, 0xa, 0x2, 0x2, 0x40, 0x41, 0x5, 0xc, 0x7, 0x2, 
    0x41, 0x42, 0x7, 0xb, 0x2, 0x2, 0x42, 0x43, 0x7, 0x7, 0x2, 0x2, 0x43, 
    0x44, 0x7, 0xa, 0x2, 0x2, 0x44, 0x45, 0x5, 0xc, 0x7, 0x2, 0x45, 0x46, 
    0x7, 0xb, 0x2, 0x2, 0x46, 0x11, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 
    0x8, 0x2, 0x2, 0x48, 0x49, 0x7, 0xa, 0x2, 0x2, 0x49, 0x4a, 0x5, 0xc, 
    0x7, 0x2, 0x4a, 0x4b, 0x7, 0xb, 0x2, 0x2, 0x4b, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x4d, 0x7, 0x9, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0xa, 0x2, 0x2, 
    0x4e, 0x4f, 0x5, 0x18, 0xd, 0x2, 0x4f, 0x50, 0x7, 0xb, 0x2, 0x2, 0x50, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x5, 0x18, 0xd, 0x2, 0x52, 0x53, 
    0x7, 0x10, 0x2, 0x2, 0x53, 0x54, 0x5, 0x18, 0xd, 0x2, 0x54, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x55, 0x58, 0x5, 0x1a, 0xe, 0x2, 0x56, 0x58, 0x7, 0x4, 
    0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x19, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0xc, 0x2, 0x2, 
    0x5a, 0x5f, 0x7, 0x5, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x3, 0x2, 0x2, 0x5c, 
    0x5e, 0x7, 0x5, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x63, 0x7, 0xd, 0x2, 0x2, 0x63, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x7, 0x22, 0x26, 0x35, 0x57, 0x5f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

invParser::Initializer invParser::_init;
