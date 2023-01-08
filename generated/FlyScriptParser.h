
// Generated from FlyScriptParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"


namespace beingyi {


class  FlyScriptParser : public antlr4::Parser {
public:
  enum {
    Type_void = 1, Type_string = 2, Type_float = 3, Type_int = 4, Type_boolean = 5, 
    K_If = 6, K_Then = 7, K_Else = 8, K_Return = 9, LCurlyPar = 10, RCurlyPar = 11, 
    LSquarePar = 12, RSquarePar = 13, PLUS = 14, SUBTRACT = 15, MULTIPLY = 16, 
    DIVIDE = 17, NOT = 18, AssignEqual = 19, JudgeEqual = 20, NotEqual = 21, 
    GreaterOrEqual = 22, Greater = 23, LesserOrEqual = 24, Lesser = 25, 
    OrBoolean = 26, AndBoolean = 27, Or = 28, And = 29, Comma = 30, Semicolon = 31, 
    ID = 32, INT = 33, WS = 34, SL_COMMENT = 35, DQUOTE = 36, LPAR = 37, 
    RPAR = 38, TEXT = 39, BACKSLASH_PAREN = 40, ESCAPE_SEQUENCE = 41
  };

  enum {
    RuleFile = 0, RuleType = 1, RuleField = 2, RuleFunction = 3, RuleFunctionParameters = 4, 
    RuleFunctionParameter = 5, RuleBlock = 6, RuleStmt = 7, RuleJudgeSymbol = 8, 
    RuleExpr = 9, RuleExprList = 10, RuleStringContents = 11
  };

  explicit FlyScriptParser(antlr4::TokenStream *input);

  FlyScriptParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~FlyScriptParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class FileContext;
  class TypeContext;
  class FieldContext;
  class FunctionContext;
  class FunctionParametersContext;
  class FunctionParameterContext;
  class BlockContext;
  class StmtContext;
  class JudgeSymbolContext;
  class ExprContext;
  class ExprListContext;
  class StringContentsContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FunctionContext *> function();
    FunctionContext* function(size_t i);
    std::vector<FieldContext *> field();
    FieldContext* field(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Type_void();
    antlr4::tree::TerminalNode *Type_string();
    antlr4::tree::TerminalNode *Type_float();
    antlr4::tree::TerminalNode *Type_int();
    antlr4::tree::TerminalNode *Type_boolean();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  FieldContext : public antlr4::ParserRuleContext {
  public:
    FieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Semicolon();
    antlr4::tree::TerminalNode *AssignEqual();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldContext* field();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    BlockContext *block();
    FunctionParametersContext *functionParameters();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  FunctionParametersContext : public antlr4::ParserRuleContext {
  public:
    FunctionParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FunctionParameterContext *> functionParameter();
    FunctionParameterContext* functionParameter(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionParametersContext* functionParameters();

  class  FunctionParameterContext : public antlr4::ParserRuleContext {
  public:
    FunctionParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionParameterContext* functionParameter();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCurlyPar();
    antlr4::tree::TerminalNode *RCurlyPar();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  InvokeStmtContext : public StmtContext {
  public:
    InvokeStmtContext(StmtContext *ctx);

    ExprContext *expr();
    antlr4::tree::TerminalNode *Semicolon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CodeBlockContext : public StmtContext {
  public:
    CodeBlockContext(StmtContext *ctx);

    BlockContext *block();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfElseStmtContext : public StmtContext {
  public:
    IfElseStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *K_If();
    antlr4::tree::TerminalNode *LPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    antlr4::tree::TerminalNode *K_Else();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignStmtContext : public StmtContext {
  public:
    AssignStmtContext(StmtContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *AssignEqual();
    antlr4::tree::TerminalNode *Semicolon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnStmtContext : public StmtContext {
  public:
    ReturnStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *K_Return();
    antlr4::tree::TerminalNode *Semicolon();
    ExprContext *expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarStmtContext : public StmtContext {
  public:
    VarStmtContext(StmtContext *ctx);

    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Semicolon();
    antlr4::tree::TerminalNode *AssignEqual();
    ExprContext *expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StmtContext* stmt();

  class  JudgeSymbolContext : public antlr4::ParserRuleContext {
  public:
    JudgeSymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    JudgeSymbolContext() = default;
    void copyFrom(JudgeSymbolContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  JudgeEqualSymbolContext : public JudgeSymbolContext {
  public:
    JudgeEqualSymbolContext(JudgeSymbolContext *ctx);

    antlr4::tree::TerminalNode *JudgeEqual();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GreaterOrEqualSymbolContext : public JudgeSymbolContext {
  public:
    GreaterOrEqualSymbolContext(JudgeSymbolContext *ctx);

    antlr4::tree::TerminalNode *GreaterOrEqual();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LesserOrEqualSymbolContext : public JudgeSymbolContext {
  public:
    LesserOrEqualSymbolContext(JudgeSymbolContext *ctx);

    antlr4::tree::TerminalNode *LesserOrEqual();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotEqualSymbolContext : public JudgeSymbolContext {
  public:
    NotEqualSymbolContext(JudgeSymbolContext *ctx);

    antlr4::tree::TerminalNode *NotEqual();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GreaterSymbolContext : public JudgeSymbolContext {
  public:
    GreaterSymbolContext(JudgeSymbolContext *ctx);

    antlr4::tree::TerminalNode *Greater();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LesserSymbolContext : public JudgeSymbolContext {
  public:
    LesserSymbolContext(JudgeSymbolContext *ctx);

    antlr4::tree::TerminalNode *Lesser();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  JudgeSymbolContext* judgeSymbol();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  InvokeExprContext : public ExprContext {
  public:
    InvokeExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    ExprListContext *exprList();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntExprContext : public ExprContext {
  public:
    IntExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *INT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BooleanExprContext : public ExprContext {
  public:
    BooleanExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    JudgeSymbolContext *judgeSymbol();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OrExprContext : public ExprContext {
  public:
    OrExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *Or();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParensExprContext : public ExprContext {
  public:
    ParensExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *LPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringExprContext : public ExprContext {
  public:
    StringExprContext(ExprContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> DQUOTE();
    antlr4::tree::TerminalNode* DQUOTE(size_t i);
    std::vector<StringContentsContext *> stringContents();
    StringContentsContext* stringContents(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlusSubExprContext : public ExprContext {
  public:
    PlusSubExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *SUBTRACT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotExprContext : public ExprContext {
  public:
    NotExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *NOT();
    ExprContext *expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OrBooleanExprContext : public ExprContext {
  public:
    OrBooleanExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *OrBoolean();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AndBooleanExprContext : public ExprContext {
  public:
    AndBooleanExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *AndBoolean();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayGetExprContext : public ExprContext {
  public:
    ArrayGetExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LSquarePar();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RSquarePar();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulDivExprContext : public ExprContext {
  public:
    MulDivExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdentifierExprContext : public ExprContext {
  public:
    IdentifierExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AndExprContext : public ExprContext {
  public:
    AndExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *And();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  ExprListContext : public antlr4::ParserRuleContext {
  public:
    ExprListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprListContext* exprList();

  class  StringContentsContext : public antlr4::ParserRuleContext {
  public:
    StringContentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEXT();
    antlr4::tree::TerminalNode *ESCAPE_SEQUENCE();
    antlr4::tree::TerminalNode *BACKSLASH_PAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringContentsContext* stringContents();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace beingyi
