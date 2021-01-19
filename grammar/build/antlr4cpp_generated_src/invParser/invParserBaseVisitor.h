
// Generated from invParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "invParserVisitor.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of invParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  invParserBaseVisitor : public invParserVisitor {
public:

  virtual antlrcpp::Any visitInput(invParser::InputContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuans(invParser::QuansContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuan(invParser::QuanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNoquans(invParser::NoquansContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGor(invParser::GorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGand(invParser::GandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGno(invParser::GnoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGpos(invParser::GposContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGsub(invParser::GsubContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlrcpptest
