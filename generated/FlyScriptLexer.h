
// Generated from FlyScriptLexer.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"


namespace beingyi {


class  FlyScriptLexer : public antlr4::Lexer {
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
