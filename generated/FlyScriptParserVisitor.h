
// Generated from FlyScriptParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "FlyScriptParser.h"


namespace beingyi {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by FlyScriptParser.
 */
class  FlyScriptParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FlyScriptParser.
   */
    virtual std::any visitFile(FlyScriptParser::FileContext *context) = 0;

    virtual std::any visitType(FlyScriptParser::TypeContext *context) = 0;

    virtual std::any visitField(FlyScriptParser::FieldContext *context) = 0;

    virtual std::any visitFunction(FlyScriptParser::FunctionContext *context) = 0;

    virtual std::any visitFunctionParameters(FlyScriptParser::FunctionParametersContext *context) = 0;

    virtual std::any visitFunctionParameter(FlyScriptParser::FunctionParameterContext *context) = 0;

    virtual std::any visitBlock(FlyScriptParser::BlockContext *context) = 0;

    virtual std::any visitCodeBlock(FlyScriptParser::CodeBlockContext *context) = 0;

    virtual std::any visitVarStmt(FlyScriptParser::VarStmtContext *context) = 0;

    virtual std::any visitIfElseStmt(FlyScriptParser::IfElseStmtContext *context) = 0;

    virtual std::any visitWhileStmt(FlyScriptParser::WhileStmtContext *context) = 0;

    virtual std::any visitBreakStmt(FlyScriptParser::BreakStmtContext *context) = 0;

    virtual std::any visitReturnStmt(FlyScriptParser::ReturnStmtContext *context) = 0;

    virtual std::any visitAssignStmt(FlyScriptParser::AssignStmtContext *context) = 0;

    virtual std::any visitInvokeStmt(FlyScriptParser::InvokeStmtContext *context) = 0;

    virtual std::any visitJudgeEqualSymbol(FlyScriptParser::JudgeEqualSymbolContext *context) = 0;

    virtual std::any visitNotEqualSymbol(FlyScriptParser::NotEqualSymbolContext *context) = 0;

    virtual std::any visitGreaterOrEqualSymbol(FlyScriptParser::GreaterOrEqualSymbolContext *context) = 0;

    virtual std::any visitGreaterSymbol(FlyScriptParser::GreaterSymbolContext *context) = 0;

    virtual std::any visitLesserOrEqualSymbol(FlyScriptParser::LesserOrEqualSymbolContext *context) = 0;

    virtual std::any visitLesserSymbol(FlyScriptParser::LesserSymbolContext *context) = 0;

    virtual std::any visitInvokeExpr(FlyScriptParser::InvokeExprContext *context) = 0;

    virtual std::any visitIntExpr(FlyScriptParser::IntExprContext *context) = 0;

    virtual std::any visitBooleanExpr(FlyScriptParser::BooleanExprContext *context) = 0;

    virtual std::any visitOrExpr(FlyScriptParser::OrExprContext *context) = 0;

    virtual std::any visitBooleanTrueExpr(FlyScriptParser::BooleanTrueExprContext *context) = 0;

    virtual std::any visitParensExpr(FlyScriptParser::ParensExprContext *context) = 0;

    virtual std::any visitStringExpr(FlyScriptParser::StringExprContext *context) = 0;

    virtual std::any visitPlusSubExpr(FlyScriptParser::PlusSubExprContext *context) = 0;

    virtual std::any visitNotExpr(FlyScriptParser::NotExprContext *context) = 0;

    virtual std::any visitOrBooleanExpr(FlyScriptParser::OrBooleanExprContext *context) = 0;

    virtual std::any visitAndBooleanExpr(FlyScriptParser::AndBooleanExprContext *context) = 0;

    virtual std::any visitArrayGetExpr(FlyScriptParser::ArrayGetExprContext *context) = 0;

    virtual std::any visitMulDivExpr(FlyScriptParser::MulDivExprContext *context) = 0;

    virtual std::any visitBooleanFalseExpr(FlyScriptParser::BooleanFalseExprContext *context) = 0;

    virtual std::any visitIdentifierExpr(FlyScriptParser::IdentifierExprContext *context) = 0;

    virtual std::any visitAndExpr(FlyScriptParser::AndExprContext *context) = 0;

    virtual std::any visitExprList(FlyScriptParser::ExprListContext *context) = 0;

    virtual std::any visitStringContents(FlyScriptParser::StringContentsContext *context) = 0;


};

}  // namespace beingyi
