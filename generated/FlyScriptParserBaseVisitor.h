
// Generated from FlyScriptParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "FlyScriptParserVisitor.h"


namespace beingyi {

/**
 * This class provides an empty implementation of FlyScriptParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FlyScriptParserBaseVisitor : public FlyScriptParserVisitor {
public:

  virtual std::any visitFile(FlyScriptParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(FlyScriptParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitField(FlyScriptParser::FieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(FlyScriptParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionParameters(FlyScriptParser::FunctionParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionParameter(FlyScriptParser::FunctionParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(FlyScriptParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCodeBlock(FlyScriptParser::CodeBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarStmt(FlyScriptParser::VarStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfElseStmt(FlyScriptParser::IfElseStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(FlyScriptParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(FlyScriptParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(FlyScriptParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignStmt(FlyScriptParser::AssignStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInvokeStmt(FlyScriptParser::InvokeStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJudgeEqualSymbol(FlyScriptParser::JudgeEqualSymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotEqualSymbol(FlyScriptParser::NotEqualSymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGreaterOrEqualSymbol(FlyScriptParser::GreaterOrEqualSymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGreaterSymbol(FlyScriptParser::GreaterSymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLesserOrEqualSymbol(FlyScriptParser::LesserOrEqualSymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLesserSymbol(FlyScriptParser::LesserSymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInvokeExpr(FlyScriptParser::InvokeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntExpr(FlyScriptParser::IntExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanExpr(FlyScriptParser::BooleanExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(FlyScriptParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanTrueExpr(FlyScriptParser::BooleanTrueExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParensExpr(FlyScriptParser::ParensExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringExpr(FlyScriptParser::StringExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlusSubExpr(FlyScriptParser::PlusSubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpr(FlyScriptParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrBooleanExpr(FlyScriptParser::OrBooleanExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndBooleanExpr(FlyScriptParser::AndBooleanExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayGetExpr(FlyScriptParser::ArrayGetExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulDivExpr(FlyScriptParser::MulDivExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanFalseExpr(FlyScriptParser::BooleanFalseExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierExpr(FlyScriptParser::IdentifierExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(FlyScriptParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprList(FlyScriptParser::ExprListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringContents(FlyScriptParser::StringContentsContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace beingyi
