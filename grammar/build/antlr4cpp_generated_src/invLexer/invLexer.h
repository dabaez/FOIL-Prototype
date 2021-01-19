
// Generated from invLexer.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  invLexer : public antlr4::Lexer {
public:
  enum {
    COMMA = 1, VARIABLE = 2, CONSTANT = 3, BOOL = 4, OR = 5, AND = 6, NO = 7, 
    POSITIVE = 8, OPENP = 9, CLOSEP = 10, EXISTS = 11, FORALL = 12, SUB = 13, 
    WHITESPACE = 14
  };

  explicit invLexer(antlr4::CharStream *input);
  ~invLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpptest
