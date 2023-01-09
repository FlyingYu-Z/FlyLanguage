
// Generated from FlyScriptLexer.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"


namespace beingyi {


class  FlyScriptLexer : public antlr4::Lexer {
public:
  enum {
    Type_void = 1, Type_string = 2, Type_float = 3, Type_int = 4, Type_boolean = 5, 
    K_If = 6, K_Then = 7, K_Else = 8, K_While = 9, K_Break = 10, K_Return = 11, 
    Kv_True = 12, Kv_False = 13, LCurlyPar = 14, RCurlyPar = 15, LSquarePar = 16, 
    RSquarePar = 17, PLUS = 18, SUBTRACT = 19, MULTIPLY = 20, DIVIDE = 21, 
    NOT = 22, AssignEqual = 23, JudgeEqual = 24, NotEqual = 25, GreaterOrEqual = 26, 
    Greater = 27, LesserOrEqual = 28, Lesser = 29, OrBoolean = 30, AndBoolean = 31, 
    Or = 32, And = 33, Comma = 34, Semicolon = 35, ID = 36, INT = 37, WS = 38, 
    SL_COMMENT = 39, DQUOTE = 40, LPAR = 41, RPAR = 42, TEXT = 43, BACKSLASH_PAREN = 44, 
    ESCAPE_SEQUENCE = 45
  };

  enum {
    IN_STRING = 1
  };

  explicit FlyScriptLexer(antlr4::CharStream *input);

  ~FlyScriptLexer() override;


      int nesting = 0;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void LPARAction(antlr4::RuleContext *context, size_t actionIndex);
  void RPARAction(antlr4::RuleContext *context, size_t actionIndex);
  void BACKSLASH_PARENAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace beingyi
