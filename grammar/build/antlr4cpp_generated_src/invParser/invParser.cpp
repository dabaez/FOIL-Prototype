
// Generated from invParser.g4 by ANTLR 4.9.1



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

invParser::NoquansContext* invParser::InputContext::noquans() {
  return getRuleContext<invParser::NoquansContext>(0);
}


size_t invParser::InputContext::getRuleIndex() const {
  return invParser::RuleInput;
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
    setState(18);
    quans();
    setState(19);
    noquans();
   
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


size_t invParser::QuansContext::getRuleIndex() const {
  return invParser::RuleQuans;
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
    setState(25);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case invParser::EXISTS:
      case invParser::FORALL: {
        enterOuterAlt(_localctx, 1);
        setState(21);
        quan();
        setState(22);
        quans();
        break;
      }

      case invParser::VARIABLE:
      case invParser::CONSTANT:
      case invParser::NO:
      case invParser::POSITIVE:
      case invParser::OPENP: {
        enterOuterAlt(_localctx, 2);

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

tree::TerminalNode* invParser::QuanContext::VARIABLE() {
  return getToken(invParser::VARIABLE, 0);
}

tree::TerminalNode* invParser::QuanContext::COMMA() {
  return getToken(invParser::COMMA, 0);
}

tree::TerminalNode* invParser::QuanContext::EXISTS() {
  return getToken(invParser::EXISTS, 0);
}

tree::TerminalNode* invParser::QuanContext::FORALL() {
  return getToken(invParser::FORALL, 0);
}


size_t invParser::QuanContext::getRuleIndex() const {
  return invParser::RuleQuan;
}


invParser::QuanContext* invParser::quan() {
  QuanContext *_localctx = _tracker.createInstance<QuanContext>(_ctx, getState());
  enterRule(_localctx, 4, invParser::RuleQuan);
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
    setState(27);
    _la = _input->LA(1);
    if (!(_la == invParser::EXISTS

    || _la == invParser::FORALL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(28);
    match(invParser::VARIABLE);
    setState(29);
    match(invParser::COMMA);
   
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


invParser::NoquansContext* invParser::noquans() {
  NoquansContext *_localctx = _tracker.createInstance<NoquansContext>(_ctx, getState());
  enterRule(_localctx, 6, invParser::RuleNoquans);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(36);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(31);
      gor();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(32);
      gand();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(33);
      gno();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(34);
      gpos();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(35);
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


invParser::GorContext* invParser::gor() {
  GorContext *_localctx = _tracker.createInstance<GorContext>(_ctx, getState());
  enterRule(_localctx, 8, invParser::RuleGor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    match(invParser::OPENP);
    setState(39);
    noquans();
    setState(40);
    match(invParser::CLOSEP);
    setState(41);
    match(invParser::OR);
    setState(42);
    match(invParser::OPENP);
    setState(43);
    noquans();
    setState(44);
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


invParser::GandContext* invParser::gand() {
  GandContext *_localctx = _tracker.createInstance<GandContext>(_ctx, getState());
  enterRule(_localctx, 10, invParser::RuleGand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(invParser::OPENP);
    setState(47);
    noquans();
    setState(48);
    match(invParser::CLOSEP);
    setState(49);
    match(invParser::AND);
    setState(50);
    match(invParser::OPENP);
    setState(51);
    noquans();
    setState(52);
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


invParser::GnoContext* invParser::gno() {
  GnoContext *_localctx = _tracker.createInstance<GnoContext>(_ctx, getState());
  enterRule(_localctx, 12, invParser::RuleGno);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(invParser::NO);
    setState(55);
    match(invParser::OPENP);
    setState(56);
    noquans();
    setState(57);
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

tree::TerminalNode* invParser::GposContext::CLOSEP() {
  return getToken(invParser::CLOSEP, 0);
}

tree::TerminalNode* invParser::GposContext::CONSTANT() {
  return getToken(invParser::CONSTANT, 0);
}

tree::TerminalNode* invParser::GposContext::VARIABLE() {
  return getToken(invParser::VARIABLE, 0);
}


size_t invParser::GposContext::getRuleIndex() const {
  return invParser::RuleGpos;
}


invParser::GposContext* invParser::gpos() {
  GposContext *_localctx = _tracker.createInstance<GposContext>(_ctx, getState());
  enterRule(_localctx, 14, invParser::RuleGpos);
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
    setState(59);
    match(invParser::POSITIVE);
    setState(60);
    match(invParser::OPENP);
    setState(61);
    _la = _input->LA(1);
    if (!(_la == invParser::VARIABLE

    || _la == invParser::CONSTANT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(62);
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

tree::TerminalNode* invParser::GsubContext::SUB() {
  return getToken(invParser::SUB, 0);
}

std::vector<tree::TerminalNode *> invParser::GsubContext::CONSTANT() {
  return getTokens(invParser::CONSTANT);
}

tree::TerminalNode* invParser::GsubContext::CONSTANT(size_t i) {
  return getToken(invParser::CONSTANT, i);
}

std::vector<tree::TerminalNode *> invParser::GsubContext::VARIABLE() {
  return getTokens(invParser::VARIABLE);
}

tree::TerminalNode* invParser::GsubContext::VARIABLE(size_t i) {
  return getToken(invParser::VARIABLE, i);
}


size_t invParser::GsubContext::getRuleIndex() const {
  return invParser::RuleGsub;
}


invParser::GsubContext* invParser::gsub() {
  GsubContext *_localctx = _tracker.createInstance<GsubContext>(_ctx, getState());
  enterRule(_localctx, 16, invParser::RuleGsub);
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
    setState(64);
    _la = _input->LA(1);
    if (!(_la == invParser::VARIABLE

    || _la == invParser::CONSTANT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(65);
    match(invParser::SUB);
    setState(66);
    _la = _input->LA(1);
    if (!(_la == invParser::VARIABLE

    || _la == invParser::CONSTANT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
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
  "input", "quans", "quan", "noquans", "gor", "gand", "gno", "gpos", "gsub"
};

std::vector<std::string> invParser::_literalNames = {
  "", "','", "", "", "'V'", "'^'", "'~'", "'P'", "'('", "')'", "'EXISTS'", 
  "'FORALL'", "'<='", "' '"
};

std::vector<std::string> invParser::_symbolicNames = {
  "", "COMMA", "VARIABLE", "CONSTANT", "OR", "AND", "NO", "POSITIVE", "OPENP", 
  "CLOSEP", "EXISTS", "FORALL", "SUB", "WHITESPACE"
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
    0x3, 0xf, 0x47, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1c, 
    0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x27, 0xa, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x2, 0x2, 0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x2, 0x4, 0x3, 0x2, 0xc, 0xd, 0x3, 0x2, 0x4, 0x5, 0x2, 0x42, 0x2, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x26, 0x3, 0x2, 0x2, 0x2, 0xa, 0x28, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x30, 0x3, 0x2, 0x2, 0x2, 0xe, 0x38, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x12, 0x42, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x15, 0x5, 0x4, 0x3, 0x2, 0x15, 0x16, 0x5, 0x8, 0x5, 0x2, 0x16, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x5, 0x6, 0x4, 0x2, 0x18, 0x19, 0x5, 
    0x4, 0x3, 0x2, 0x19, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1c, 0x3, 0x2, 
    0x2, 0x2, 0x1b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1a, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x9, 0x2, 0x2, 0x2, 
    0x1e, 0x1f, 0x7, 0x4, 0x2, 0x2, 0x1f, 0x20, 0x7, 0x3, 0x2, 0x2, 0x20, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x21, 0x27, 0x5, 0xa, 0x6, 0x2, 0x22, 0x27, 
    0x5, 0xc, 0x7, 0x2, 0x23, 0x27, 0x5, 0xe, 0x8, 0x2, 0x24, 0x27, 0x5, 
    0x10, 0x9, 0x2, 0x25, 0x27, 0x5, 0x12, 0xa, 0x2, 0x26, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x22, 0x3, 0x2, 0x2, 0x2, 0x26, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x9, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0xa, 0x2, 0x2, 0x29, 
    0x2a, 0x5, 0x8, 0x5, 0x2, 0x2a, 0x2b, 0x7, 0xb, 0x2, 0x2, 0x2b, 0x2c, 
    0x7, 0x6, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0xa, 0x2, 0x2, 0x2d, 0x2e, 0x5, 
    0x8, 0x5, 0x2, 0x2e, 0x2f, 0x7, 0xb, 0x2, 0x2, 0x2f, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x31, 0x7, 0xa, 0x2, 0x2, 0x31, 0x32, 0x5, 0x8, 0x5, 
    0x2, 0x32, 0x33, 0x7, 0xb, 0x2, 0x2, 0x33, 0x34, 0x7, 0x7, 0x2, 0x2, 
    0x34, 0x35, 0x7, 0xa, 0x2, 0x2, 0x35, 0x36, 0x5, 0x8, 0x5, 0x2, 0x36, 
    0x37, 0x7, 0xb, 0x2, 0x2, 0x37, 0xd, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 
    0x7, 0x8, 0x2, 0x2, 0x39, 0x3a, 0x7, 0xa, 0x2, 0x2, 0x3a, 0x3b, 0x5, 
    0x8, 0x5, 0x2, 0x3b, 0x3c, 0x7, 0xb, 0x2, 0x2, 0x3c, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x3e, 0x7, 0x9, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0xa, 0x2, 
    0x2, 0x3f, 0x40, 0x9, 0x3, 0x2, 0x2, 0x40, 0x41, 0x7, 0xb, 0x2, 0x2, 
    0x41, 0x11, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x9, 0x3, 0x2, 0x2, 0x43, 
    0x44, 0x7, 0xe, 0x2, 0x2, 0x44, 0x45, 0x9, 0x3, 0x2, 0x2, 0x45, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x1b, 0x26, 
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
