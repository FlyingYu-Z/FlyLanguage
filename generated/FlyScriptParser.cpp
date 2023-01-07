
// Generated from FlyScriptParser.g4 by ANTLR 4.11.1


#include "FlyScriptParserVisitor.h"

#include "FlyScriptParser.h"


using namespace antlrcpp;
using namespace beingyi;

using namespace antlr4;

namespace {

struct FlyScriptParserStaticData final {
  FlyScriptParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FlyScriptParserStaticData(const FlyScriptParserStaticData&) = delete;
  FlyScriptParserStaticData(FlyScriptParserStaticData&&) = delete;
  FlyScriptParserStaticData& operator=(const FlyScriptParserStaticData&) = delete;
  FlyScriptParserStaticData& operator=(FlyScriptParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag flyscriptparserParserOnceFlag;
FlyScriptParserStaticData *flyscriptparserParserStaticData = nullptr;

void flyscriptparserParserInitialize() {
  assert(flyscriptparserParserStaticData == nullptr);
  auto staticData = std::make_unique<FlyScriptParserStaticData>(
    std::vector<std::string>{
      "file", "type", "field", "function", "functionParameters", "functionParameter", 
      "block", "stat", "judgeSymbol", "expr", "exprList", "stringContents"
    },
    std::vector<std::string>{
      "", "'void'", "'string'", "'float'", "'int'", "'boolean'", "'if'", 
      "'then'", "'else'", "'return'", "'{'", "'}'", "'['", "']'", "'+'", 
      "'-'", "'*'", "'/'", "'!'", "'='", "'=='", "'!='", "'>='", "'>'", 
      "'<='", "'<'", "'||'", "'&&'", "'|'", "'&'", "','", "';'", "", "", 
      "", "", "", "'('", "')'", "", "'\\('"
    },
    std::vector<std::string>{
      "", "Type_void", "Type_string", "Type_float", "Type_int", "Type_boolean", 
      "K_If", "K_Then", "K_Else", "K_Return", "LCurlyPar", "RCurlyPar", 
      "LSquarePar", "RSquarePar", "PLUS", "SUBTRACT", "MULTIPLY", "DIVIDE", 
      "NOT", "AssignEqual", "JudgeEqual", "NotEqual", "GreaterOrEqual", 
      "Greater", "LesserOrEqual", "Lesser", "OrBoolean", "AndBoolean", "Or", 
      "And", "Comma", "Semicolon", "ID", "INT", "WS", "SL_COMMENT", "DQUOTE", 
      "LPAR", "RPAR", "TEXT", "BACKSLASH_PAREN", "ESCAPE_SEQUENCE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,185,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,4,0,28,8,0,11,0,
  	12,0,29,1,1,1,1,1,2,1,2,1,2,1,2,3,2,38,8,2,1,2,1,2,1,3,1,3,1,3,1,3,3,
  	3,46,8,3,1,3,1,3,1,3,1,4,1,4,1,4,5,4,54,8,4,10,4,12,4,57,9,4,1,5,1,5,
  	1,5,1,6,1,6,5,6,64,8,6,10,6,12,6,67,9,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,3,
  	7,76,8,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,87,8,7,1,7,1,7,3,7,91,
  	8,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,102,8,7,1,8,1,8,1,8,1,8,1,
  	8,1,8,3,8,110,8,8,1,9,1,9,1,9,1,9,3,9,116,8,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,5,9,130,8,9,10,9,12,9,133,9,9,1,9,1,9,1,9,1,9,
  	1,9,3,9,140,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,164,8,9,10,9,12,9,167,9,9,1,10,
  	1,10,1,10,5,10,172,8,10,10,10,12,10,175,9,10,1,11,1,11,1,11,1,11,1,11,
  	1,11,3,11,183,8,11,1,11,0,1,18,12,0,2,4,6,8,10,12,14,16,18,20,22,0,3,
  	1,0,1,5,1,0,16,17,1,0,14,15,210,0,27,1,0,0,0,2,31,1,0,0,0,4,33,1,0,0,
  	0,6,41,1,0,0,0,8,50,1,0,0,0,10,58,1,0,0,0,12,61,1,0,0,0,14,101,1,0,0,
  	0,16,109,1,0,0,0,18,139,1,0,0,0,20,168,1,0,0,0,22,182,1,0,0,0,24,28,3,
  	6,3,0,25,28,3,4,2,0,26,28,3,14,7,0,27,24,1,0,0,0,27,25,1,0,0,0,27,26,
  	1,0,0,0,28,29,1,0,0,0,29,27,1,0,0,0,29,30,1,0,0,0,30,1,1,0,0,0,31,32,
  	7,0,0,0,32,3,1,0,0,0,33,34,3,2,1,0,34,37,5,32,0,0,35,36,5,19,0,0,36,38,
  	3,18,9,0,37,35,1,0,0,0,37,38,1,0,0,0,38,39,1,0,0,0,39,40,5,31,0,0,40,
  	5,1,0,0,0,41,42,3,2,1,0,42,43,5,32,0,0,43,45,5,37,0,0,44,46,3,8,4,0,45,
  	44,1,0,0,0,45,46,1,0,0,0,46,47,1,0,0,0,47,48,5,38,0,0,48,49,3,12,6,0,
  	49,7,1,0,0,0,50,55,3,10,5,0,51,52,5,30,0,0,52,54,3,10,5,0,53,51,1,0,0,
  	0,54,57,1,0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,9,1,0,0,0,57,55,1,0,0,
  	0,58,59,3,2,1,0,59,60,5,32,0,0,60,11,1,0,0,0,61,65,5,10,0,0,62,64,3,14,
  	7,0,63,62,1,0,0,0,64,67,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,68,1,0,
  	0,0,67,65,1,0,0,0,68,69,5,11,0,0,69,13,1,0,0,0,70,102,3,12,6,0,71,72,
  	3,2,1,0,72,75,5,32,0,0,73,74,5,19,0,0,74,76,3,18,9,0,75,73,1,0,0,0,75,
  	76,1,0,0,0,76,77,1,0,0,0,77,78,5,31,0,0,78,102,1,0,0,0,79,80,5,6,0,0,
  	80,81,5,37,0,0,81,82,3,18,9,0,82,83,5,38,0,0,83,86,3,12,6,0,84,85,5,8,
  	0,0,85,87,3,12,6,0,86,84,1,0,0,0,86,87,1,0,0,0,87,102,1,0,0,0,88,90,5,
  	9,0,0,89,91,3,18,9,0,90,89,1,0,0,0,90,91,1,0,0,0,91,92,1,0,0,0,92,102,
  	5,31,0,0,93,94,3,18,9,0,94,95,5,19,0,0,95,96,3,18,9,0,96,97,5,31,0,0,
  	97,102,1,0,0,0,98,99,3,18,9,0,99,100,5,31,0,0,100,102,1,0,0,0,101,70,
  	1,0,0,0,101,71,1,0,0,0,101,79,1,0,0,0,101,88,1,0,0,0,101,93,1,0,0,0,101,
  	98,1,0,0,0,102,15,1,0,0,0,103,110,5,20,0,0,104,110,5,21,0,0,105,110,5,
  	22,0,0,106,110,5,23,0,0,107,110,5,24,0,0,108,110,5,25,0,0,109,103,1,0,
  	0,0,109,104,1,0,0,0,109,105,1,0,0,0,109,106,1,0,0,0,109,107,1,0,0,0,109,
  	108,1,0,0,0,110,17,1,0,0,0,111,112,6,9,-1,0,112,113,5,32,0,0,113,115,
  	5,37,0,0,114,116,3,20,10,0,115,114,1,0,0,0,115,116,1,0,0,0,116,117,1,
  	0,0,0,117,140,5,38,0,0,118,119,5,32,0,0,119,120,5,12,0,0,120,121,3,18,
  	9,0,121,122,5,13,0,0,122,140,1,0,0,0,123,124,5,18,0,0,124,140,3,18,9,
  	12,125,140,5,32,0,0,126,140,5,33,0,0,127,131,5,36,0,0,128,130,3,22,11,
  	0,129,128,1,0,0,0,130,133,1,0,0,0,131,129,1,0,0,0,131,132,1,0,0,0,132,
  	134,1,0,0,0,133,131,1,0,0,0,134,140,5,36,0,0,135,136,5,37,0,0,136,137,
  	3,18,9,0,137,138,5,38,0,0,138,140,1,0,0,0,139,111,1,0,0,0,139,118,1,0,
  	0,0,139,123,1,0,0,0,139,125,1,0,0,0,139,126,1,0,0,0,139,127,1,0,0,0,139,
  	135,1,0,0,0,140,165,1,0,0,0,141,142,10,11,0,0,142,143,7,1,0,0,143,164,
  	3,18,9,12,144,145,10,10,0,0,145,146,7,2,0,0,146,164,3,18,9,11,147,148,
  	10,9,0,0,148,149,5,28,0,0,149,164,3,18,9,10,150,151,10,8,0,0,151,152,
  	5,29,0,0,152,164,3,18,9,9,153,154,10,7,0,0,154,155,3,16,8,0,155,156,3,
  	18,9,8,156,164,1,0,0,0,157,158,10,6,0,0,158,159,5,26,0,0,159,164,3,18,
  	9,7,160,161,10,5,0,0,161,162,5,27,0,0,162,164,3,18,9,6,163,141,1,0,0,
  	0,163,144,1,0,0,0,163,147,1,0,0,0,163,150,1,0,0,0,163,153,1,0,0,0,163,
  	157,1,0,0,0,163,160,1,0,0,0,164,167,1,0,0,0,165,163,1,0,0,0,165,166,1,
  	0,0,0,166,19,1,0,0,0,167,165,1,0,0,0,168,173,3,18,9,0,169,170,5,30,0,
  	0,170,172,3,18,9,0,171,169,1,0,0,0,172,175,1,0,0,0,173,171,1,0,0,0,173,
  	174,1,0,0,0,174,21,1,0,0,0,175,173,1,0,0,0,176,183,5,39,0,0,177,183,5,
  	41,0,0,178,179,5,40,0,0,179,180,3,18,9,0,180,181,5,38,0,0,181,183,1,0,
  	0,0,182,176,1,0,0,0,182,177,1,0,0,0,182,178,1,0,0,0,183,23,1,0,0,0,18,
  	27,29,37,45,55,65,75,86,90,101,109,115,131,139,163,165,173,182
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  flyscriptparserParserStaticData = staticData.release();
}

}

FlyScriptParser::FlyScriptParser(TokenStream *input) : FlyScriptParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

FlyScriptParser::FlyScriptParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  FlyScriptParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *flyscriptparserParserStaticData->atn, flyscriptparserParserStaticData->decisionToDFA, flyscriptparserParserStaticData->sharedContextCache, options);
}

FlyScriptParser::~FlyScriptParser() {
  delete _interpreter;
}

const atn::ATN& FlyScriptParser::getATN() const {
  return *flyscriptparserParserStaticData->atn;
}

std::string FlyScriptParser::getGrammarFileName() const {
  return "FlyScriptParser.g4";
}

const std::vector<std::string>& FlyScriptParser::getRuleNames() const {
  return flyscriptparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& FlyScriptParser::getVocabulary() const {
  return flyscriptparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FlyScriptParser::getSerializedATN() const {
  return flyscriptparserParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

FlyScriptParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlyScriptParser::FunctionContext *> FlyScriptParser::FileContext::function() {
  return getRuleContexts<FlyScriptParser::FunctionContext>();
}

FlyScriptParser::FunctionContext* FlyScriptParser::FileContext::function(size_t i) {
  return getRuleContext<FlyScriptParser::FunctionContext>(i);
}

std::vector<FlyScriptParser::FieldContext *> FlyScriptParser::FileContext::field() {
  return getRuleContexts<FlyScriptParser::FieldContext>();
}

FlyScriptParser::FieldContext* FlyScriptParser::FileContext::field(size_t i) {
  return getRuleContext<FlyScriptParser::FieldContext>(i);
}

std::vector<FlyScriptParser::StatContext *> FlyScriptParser::FileContext::stat() {
  return getRuleContexts<FlyScriptParser::StatContext>();
}

FlyScriptParser::StatContext* FlyScriptParser::FileContext::stat(size_t i) {
  return getRuleContext<FlyScriptParser::StatContext>(i);
}


size_t FlyScriptParser::FileContext::getRuleIndex() const {
  return FlyScriptParser::RuleFile;
}


std::any FlyScriptParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

FlyScriptParser::FileContext* FlyScriptParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, FlyScriptParser::RuleFile);
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
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(27);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(24);
        function();
        break;
      }

      case 2: {
        setState(25);
        field();
        break;
      }

      case 3: {
        setState(26);
        stat();
        break;
      }

      default:
        break;
      }
      setState(29); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 219043595902) != 0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

FlyScriptParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlyScriptParser::TypeContext::Type_void() {
  return getToken(FlyScriptParser::Type_void, 0);
}

tree::TerminalNode* FlyScriptParser::TypeContext::Type_string() {
  return getToken(FlyScriptParser::Type_string, 0);
}

tree::TerminalNode* FlyScriptParser::TypeContext::Type_float() {
  return getToken(FlyScriptParser::Type_float, 0);
}

tree::TerminalNode* FlyScriptParser::TypeContext::Type_int() {
  return getToken(FlyScriptParser::Type_int, 0);
}

tree::TerminalNode* FlyScriptParser::TypeContext::Type_boolean() {
  return getToken(FlyScriptParser::Type_boolean, 0);
}


size_t FlyScriptParser::TypeContext::getRuleIndex() const {
  return FlyScriptParser::RuleType;
}


std::any FlyScriptParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

FlyScriptParser::TypeContext* FlyScriptParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 2, FlyScriptParser::RuleType);
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
    setState(31);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62) != 0)) {
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

//----------------- FieldContext ------------------------------------------------------------------

FlyScriptParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlyScriptParser::TypeContext* FlyScriptParser::FieldContext::type() {
  return getRuleContext<FlyScriptParser::TypeContext>(0);
}

tree::TerminalNode* FlyScriptParser::FieldContext::ID() {
  return getToken(FlyScriptParser::ID, 0);
}

tree::TerminalNode* FlyScriptParser::FieldContext::Semicolon() {
  return getToken(FlyScriptParser::Semicolon, 0);
}

tree::TerminalNode* FlyScriptParser::FieldContext::AssignEqual() {
  return getToken(FlyScriptParser::AssignEqual, 0);
}

FlyScriptParser::ExprContext* FlyScriptParser::FieldContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}


size_t FlyScriptParser::FieldContext::getRuleIndex() const {
  return FlyScriptParser::RuleField;
}


std::any FlyScriptParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

FlyScriptParser::FieldContext* FlyScriptParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 4, FlyScriptParser::RuleField);
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
    setState(33);
    type();
    setState(34);
    match(FlyScriptParser::ID);
    setState(37);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlyScriptParser::AssignEqual) {
      setState(35);
      match(FlyScriptParser::AssignEqual);
      setState(36);
      expr(0);
    }
    setState(39);
    match(FlyScriptParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

FlyScriptParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlyScriptParser::TypeContext* FlyScriptParser::FunctionContext::type() {
  return getRuleContext<FlyScriptParser::TypeContext>(0);
}

tree::TerminalNode* FlyScriptParser::FunctionContext::ID() {
  return getToken(FlyScriptParser::ID, 0);
}

tree::TerminalNode* FlyScriptParser::FunctionContext::LPAR() {
  return getToken(FlyScriptParser::LPAR, 0);
}

tree::TerminalNode* FlyScriptParser::FunctionContext::RPAR() {
  return getToken(FlyScriptParser::RPAR, 0);
}

FlyScriptParser::BlockContext* FlyScriptParser::FunctionContext::block() {
  return getRuleContext<FlyScriptParser::BlockContext>(0);
}

FlyScriptParser::FunctionParametersContext* FlyScriptParser::FunctionContext::functionParameters() {
  return getRuleContext<FlyScriptParser::FunctionParametersContext>(0);
}


size_t FlyScriptParser::FunctionContext::getRuleIndex() const {
  return FlyScriptParser::RuleFunction;
}


std::any FlyScriptParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

FlyScriptParser::FunctionContext* FlyScriptParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 6, FlyScriptParser::RuleFunction);
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
    setState(41);
    type();
    setState(42);
    match(FlyScriptParser::ID);
    setState(43);
    match(FlyScriptParser::LPAR);
    setState(45);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62) != 0) {
      setState(44);
      functionParameters();
    }
    setState(47);
    match(FlyScriptParser::RPAR);
    setState(48);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionParametersContext ------------------------------------------------------------------

FlyScriptParser::FunctionParametersContext::FunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlyScriptParser::FunctionParameterContext *> FlyScriptParser::FunctionParametersContext::functionParameter() {
  return getRuleContexts<FlyScriptParser::FunctionParameterContext>();
}

FlyScriptParser::FunctionParameterContext* FlyScriptParser::FunctionParametersContext::functionParameter(size_t i) {
  return getRuleContext<FlyScriptParser::FunctionParameterContext>(i);
}

std::vector<tree::TerminalNode *> FlyScriptParser::FunctionParametersContext::Comma() {
  return getTokens(FlyScriptParser::Comma);
}

tree::TerminalNode* FlyScriptParser::FunctionParametersContext::Comma(size_t i) {
  return getToken(FlyScriptParser::Comma, i);
}


size_t FlyScriptParser::FunctionParametersContext::getRuleIndex() const {
  return FlyScriptParser::RuleFunctionParameters;
}


std::any FlyScriptParser::FunctionParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionParameters(this);
  else
    return visitor->visitChildren(this);
}

FlyScriptParser::FunctionParametersContext* FlyScriptParser::functionParameters() {
  FunctionParametersContext *_localctx = _tracker.createInstance<FunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 8, FlyScriptParser::RuleFunctionParameters);
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
    setState(50);
    functionParameter();
    setState(55);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlyScriptParser::Comma) {
      setState(51);
      match(FlyScriptParser::Comma);
      setState(52);
      functionParameter();
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionParameterContext ------------------------------------------------------------------

FlyScriptParser::FunctionParameterContext::FunctionParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlyScriptParser::TypeContext* FlyScriptParser::FunctionParameterContext::type() {
  return getRuleContext<FlyScriptParser::TypeContext>(0);
}

tree::TerminalNode* FlyScriptParser::FunctionParameterContext::ID() {
  return getToken(FlyScriptParser::ID, 0);
}


size_t FlyScriptParser::FunctionParameterContext::getRuleIndex() const {
  return FlyScriptParser::RuleFunctionParameter;
}


std::any FlyScriptParser::FunctionParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionParameter(this);
  else
    return visitor->visitChildren(this);
}

FlyScriptParser::FunctionParameterContext* FlyScriptParser::functionParameter() {
  FunctionParameterContext *_localctx = _tracker.createInstance<FunctionParameterContext>(_ctx, getState());
  enterRule(_localctx, 10, FlyScriptParser::RuleFunctionParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    type();
    setState(59);
    match(FlyScriptParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

FlyScriptParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlyScriptParser::BlockContext::LCurlyPar() {
  return getToken(FlyScriptParser::LCurlyPar, 0);
}

tree::TerminalNode* FlyScriptParser::BlockContext::RCurlyPar() {
  return getToken(FlyScriptParser::RCurlyPar, 0);
}

std::vector<FlyScriptParser::StatContext *> FlyScriptParser::BlockContext::stat() {
  return getRuleContexts<FlyScriptParser::StatContext>();
}

FlyScriptParser::StatContext* FlyScriptParser::BlockContext::stat(size_t i) {
  return getRuleContext<FlyScriptParser::StatContext>(i);
}


size_t FlyScriptParser::BlockContext::getRuleIndex() const {
  return FlyScriptParser::RuleBlock;
}


std::any FlyScriptParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

FlyScriptParser::BlockContext* FlyScriptParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 12, FlyScriptParser::RuleBlock);
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
    setState(61);
    match(FlyScriptParser::LCurlyPar);
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 219043595902) != 0) {
      setState(62);
      stat();
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(68);
    match(FlyScriptParser::RCurlyPar);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

FlyScriptParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FlyScriptParser::StatContext::getRuleIndex() const {
  return FlyScriptParser::RuleStat;
}

void FlyScriptParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- InvokeStmtContext ------------------------------------------------------------------

FlyScriptParser::ExprContext* FlyScriptParser::InvokeStmtContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}

tree::TerminalNode* FlyScriptParser::InvokeStmtContext::Semicolon() {
  return getToken(FlyScriptParser::Semicolon, 0);
}

FlyScriptParser::InvokeStmtContext::InvokeStmtContext(StatContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::InvokeStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitInvokeStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CodeBlockContext ------------------------------------------------------------------

FlyScriptParser::BlockContext* FlyScriptParser::CodeBlockContext::block() {
  return getRuleContext<FlyScriptParser::BlockContext>(0);
}

FlyScriptParser::CodeBlockContext::CodeBlockContext(StatContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::CodeBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitCodeBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfElseStmtContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::IfElseStmtContext::K_If() {
  return getToken(FlyScriptParser::K_If, 0);
}

tree::TerminalNode* FlyScriptParser::IfElseStmtContext::LPAR() {
  return getToken(FlyScriptParser::LPAR, 0);
}

FlyScriptParser::ExprContext* FlyScriptParser::IfElseStmtContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}

tree::TerminalNode* FlyScriptParser::IfElseStmtContext::RPAR() {
  return getToken(FlyScriptParser::RPAR, 0);
}

std::vector<FlyScriptParser::BlockContext *> FlyScriptParser::IfElseStmtContext::block() {
  return getRuleContexts<FlyScriptParser::BlockContext>();
}

FlyScriptParser::BlockContext* FlyScriptParser::IfElseStmtContext::block(size_t i) {
  return getRuleContext<FlyScriptParser::BlockContext>(i);
}

tree::TerminalNode* FlyScriptParser::IfElseStmtContext::K_Else() {
  return getToken(FlyScriptParser::K_Else, 0);
}

FlyScriptParser::IfElseStmtContext::IfElseStmtContext(StatContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::IfElseStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitIfElseStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

std::vector<FlyScriptParser::ExprContext *> FlyScriptParser::AssignStmtContext::expr() {
  return getRuleContexts<FlyScriptParser::ExprContext>();
}

FlyScriptParser::ExprContext* FlyScriptParser::AssignStmtContext::expr(size_t i) {
  return getRuleContext<FlyScriptParser::ExprContext>(i);
}

tree::TerminalNode* FlyScriptParser::AssignStmtContext::AssignEqual() {
  return getToken(FlyScriptParser::AssignEqual, 0);
}

tree::TerminalNode* FlyScriptParser::AssignStmtContext::Semicolon() {
  return getToken(FlyScriptParser::Semicolon, 0);
}

FlyScriptParser::AssignStmtContext::AssignStmtContext(StatContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::ReturnStmtContext::K_Return() {
  return getToken(FlyScriptParser::K_Return, 0);
}

tree::TerminalNode* FlyScriptParser::ReturnStmtContext::Semicolon() {
  return getToken(FlyScriptParser::Semicolon, 0);
}

FlyScriptParser::ExprContext* FlyScriptParser::ReturnStmtContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}

FlyScriptParser::ReturnStmtContext::ReturnStmtContext(StatContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarStmtContext ------------------------------------------------------------------

FlyScriptParser::TypeContext* FlyScriptParser::VarStmtContext::type() {
  return getRuleContext<FlyScriptParser::TypeContext>(0);
}

tree::TerminalNode* FlyScriptParser::VarStmtContext::ID() {
  return getToken(FlyScriptParser::ID, 0);
}

tree::TerminalNode* FlyScriptParser::VarStmtContext::Semicolon() {
  return getToken(FlyScriptParser::Semicolon, 0);
}

tree::TerminalNode* FlyScriptParser::VarStmtContext::AssignEqual() {
  return getToken(FlyScriptParser::AssignEqual, 0);
}

FlyScriptParser::ExprContext* FlyScriptParser::VarStmtContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}

FlyScriptParser::VarStmtContext::VarStmtContext(StatContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::VarStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitVarStmt(this);
  else
    return visitor->visitChildren(this);
}
FlyScriptParser::StatContext* FlyScriptParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 14, FlyScriptParser::RuleStat);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(101);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<FlyScriptParser::CodeBlockContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(70);
      block();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<FlyScriptParser::VarStmtContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(71);
      type();
      setState(72);
      match(FlyScriptParser::ID);
      setState(75);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FlyScriptParser::AssignEqual) {
        setState(73);
        match(FlyScriptParser::AssignEqual);
        setState(74);
        expr(0);
      }
      setState(77);
      match(FlyScriptParser::Semicolon);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FlyScriptParser::IfElseStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(79);
      match(FlyScriptParser::K_If);
      setState(80);
      match(FlyScriptParser::LPAR);
      setState(81);
      expr(0);
      setState(82);
      match(FlyScriptParser::RPAR);
      setState(83);
      block();
      setState(86);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FlyScriptParser::K_Else) {
        setState(84);
        match(FlyScriptParser::K_Else);
        setState(85);
        block();
      }
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FlyScriptParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(88);
      match(FlyScriptParser::K_Return);
      setState(90);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 219043594240) != 0) {
        setState(89);
        expr(0);
      }
      setState(92);
      match(FlyScriptParser::Semicolon);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<FlyScriptParser::AssignStmtContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(93);
      expr(0);
      setState(94);
      match(FlyScriptParser::AssignEqual);
      setState(95);
      expr(0);
      setState(96);
      match(FlyScriptParser::Semicolon);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<FlyScriptParser::InvokeStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(98);
      expr(0);
      setState(99);
      match(FlyScriptParser::Semicolon);
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

//----------------- JudgeSymbolContext ------------------------------------------------------------------

FlyScriptParser::JudgeSymbolContext::JudgeSymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FlyScriptParser::JudgeSymbolContext::getRuleIndex() const {
  return FlyScriptParser::RuleJudgeSymbol;
}

void FlyScriptParser::JudgeSymbolContext::copyFrom(JudgeSymbolContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- JudgeEqualSymbolContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::JudgeEqualSymbolContext::JudgeEqual() {
  return getToken(FlyScriptParser::JudgeEqual, 0);
}

FlyScriptParser::JudgeEqualSymbolContext::JudgeEqualSymbolContext(JudgeSymbolContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::JudgeEqualSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitJudgeEqualSymbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GreaterOrEqualSymbolContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::GreaterOrEqualSymbolContext::GreaterOrEqual() {
  return getToken(FlyScriptParser::GreaterOrEqual, 0);
}

FlyScriptParser::GreaterOrEqualSymbolContext::GreaterOrEqualSymbolContext(JudgeSymbolContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::GreaterOrEqualSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitGreaterOrEqualSymbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LesserOrEqualSymbolContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::LesserOrEqualSymbolContext::LesserOrEqual() {
  return getToken(FlyScriptParser::LesserOrEqual, 0);
}

FlyScriptParser::LesserOrEqualSymbolContext::LesserOrEqualSymbolContext(JudgeSymbolContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::LesserOrEqualSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitLesserOrEqualSymbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotEqualSymbolContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::NotEqualSymbolContext::NotEqual() {
  return getToken(FlyScriptParser::NotEqual, 0);
}

FlyScriptParser::NotEqualSymbolContext::NotEqualSymbolContext(JudgeSymbolContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::NotEqualSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitNotEqualSymbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GreaterSymbolContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::GreaterSymbolContext::Greater() {
  return getToken(FlyScriptParser::Greater, 0);
}

FlyScriptParser::GreaterSymbolContext::GreaterSymbolContext(JudgeSymbolContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::GreaterSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitGreaterSymbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LesserSymbolContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::LesserSymbolContext::Lesser() {
  return getToken(FlyScriptParser::Lesser, 0);
}

FlyScriptParser::LesserSymbolContext::LesserSymbolContext(JudgeSymbolContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::LesserSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitLesserSymbol(this);
  else
    return visitor->visitChildren(this);
}
FlyScriptParser::JudgeSymbolContext* FlyScriptParser::judgeSymbol() {
  JudgeSymbolContext *_localctx = _tracker.createInstance<JudgeSymbolContext>(_ctx, getState());
  enterRule(_localctx, 16, FlyScriptParser::RuleJudgeSymbol);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlyScriptParser::JudgeEqual: {
        _localctx = _tracker.createInstance<FlyScriptParser::JudgeEqualSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(103);
        match(FlyScriptParser::JudgeEqual);
        break;
      }

      case FlyScriptParser::NotEqual: {
        _localctx = _tracker.createInstance<FlyScriptParser::NotEqualSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(104);
        match(FlyScriptParser::NotEqual);
        break;
      }

      case FlyScriptParser::GreaterOrEqual: {
        _localctx = _tracker.createInstance<FlyScriptParser::GreaterOrEqualSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(105);
        match(FlyScriptParser::GreaterOrEqual);
        break;
      }

      case FlyScriptParser::Greater: {
        _localctx = _tracker.createInstance<FlyScriptParser::GreaterSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(106);
        match(FlyScriptParser::Greater);
        break;
      }

      case FlyScriptParser::LesserOrEqual: {
        _localctx = _tracker.createInstance<FlyScriptParser::LesserOrEqualSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(107);
        match(FlyScriptParser::LesserOrEqual);
        break;
      }

      case FlyScriptParser::Lesser: {
        _localctx = _tracker.createInstance<FlyScriptParser::LesserSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(108);
        match(FlyScriptParser::Lesser);
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

//----------------- ExprContext ------------------------------------------------------------------

FlyScriptParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FlyScriptParser::ExprContext::getRuleIndex() const {
  return FlyScriptParser::RuleExpr;
}

void FlyScriptParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- InvokeExprContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::InvokeExprContext::ID() {
  return getToken(FlyScriptParser::ID, 0);
}

tree::TerminalNode* FlyScriptParser::InvokeExprContext::LPAR() {
  return getToken(FlyScriptParser::LPAR, 0);
}

tree::TerminalNode* FlyScriptParser::InvokeExprContext::RPAR() {
  return getToken(FlyScriptParser::RPAR, 0);
}

FlyScriptParser::ExprListContext* FlyScriptParser::InvokeExprContext::exprList() {
  return getRuleContext<FlyScriptParser::ExprListContext>(0);
}

FlyScriptParser::InvokeExprContext::InvokeExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::InvokeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitInvokeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntExprContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::IntExprContext::INT() {
  return getToken(FlyScriptParser::INT, 0);
}

FlyScriptParser::IntExprContext::IntExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::IntExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitIntExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BooleanExprContext ------------------------------------------------------------------

std::vector<FlyScriptParser::ExprContext *> FlyScriptParser::BooleanExprContext::expr() {
  return getRuleContexts<FlyScriptParser::ExprContext>();
}

FlyScriptParser::ExprContext* FlyScriptParser::BooleanExprContext::expr(size_t i) {
  return getRuleContext<FlyScriptParser::ExprContext>(i);
}

FlyScriptParser::JudgeSymbolContext* FlyScriptParser::BooleanExprContext::judgeSymbol() {
  return getRuleContext<FlyScriptParser::JudgeSymbolContext>(0);
}

FlyScriptParser::BooleanExprContext::BooleanExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::BooleanExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitBooleanExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<FlyScriptParser::ExprContext *> FlyScriptParser::OrExprContext::expr() {
  return getRuleContexts<FlyScriptParser::ExprContext>();
}

FlyScriptParser::ExprContext* FlyScriptParser::OrExprContext::expr(size_t i) {
  return getRuleContext<FlyScriptParser::ExprContext>(i);
}

tree::TerminalNode* FlyScriptParser::OrExprContext::Or() {
  return getToken(FlyScriptParser::Or, 0);
}

FlyScriptParser::OrExprContext::OrExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParensExprContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::ParensExprContext::LPAR() {
  return getToken(FlyScriptParser::LPAR, 0);
}

FlyScriptParser::ExprContext* FlyScriptParser::ParensExprContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}

tree::TerminalNode* FlyScriptParser::ParensExprContext::RPAR() {
  return getToken(FlyScriptParser::RPAR, 0);
}

FlyScriptParser::ParensExprContext::ParensExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::ParensExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitParensExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringExprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> FlyScriptParser::StringExprContext::DQUOTE() {
  return getTokens(FlyScriptParser::DQUOTE);
}

tree::TerminalNode* FlyScriptParser::StringExprContext::DQUOTE(size_t i) {
  return getToken(FlyScriptParser::DQUOTE, i);
}

std::vector<FlyScriptParser::StringContentsContext *> FlyScriptParser::StringExprContext::stringContents() {
  return getRuleContexts<FlyScriptParser::StringContentsContext>();
}

FlyScriptParser::StringContentsContext* FlyScriptParser::StringExprContext::stringContents(size_t i) {
  return getRuleContext<FlyScriptParser::StringContentsContext>(i);
}

FlyScriptParser::StringExprContext::StringExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::StringExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitStringExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusSubExprContext ------------------------------------------------------------------

std::vector<FlyScriptParser::ExprContext *> FlyScriptParser::PlusSubExprContext::expr() {
  return getRuleContexts<FlyScriptParser::ExprContext>();
}

FlyScriptParser::ExprContext* FlyScriptParser::PlusSubExprContext::expr(size_t i) {
  return getRuleContext<FlyScriptParser::ExprContext>(i);
}

tree::TerminalNode* FlyScriptParser::PlusSubExprContext::PLUS() {
  return getToken(FlyScriptParser::PLUS, 0);
}

tree::TerminalNode* FlyScriptParser::PlusSubExprContext::SUBTRACT() {
  return getToken(FlyScriptParser::SUBTRACT, 0);
}

FlyScriptParser::PlusSubExprContext::PlusSubExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::PlusSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitPlusSubExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::NotExprContext::NOT() {
  return getToken(FlyScriptParser::NOT, 0);
}

FlyScriptParser::ExprContext* FlyScriptParser::NotExprContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}

FlyScriptParser::NotExprContext::NotExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrBooleanExprContext ------------------------------------------------------------------

std::vector<FlyScriptParser::ExprContext *> FlyScriptParser::OrBooleanExprContext::expr() {
  return getRuleContexts<FlyScriptParser::ExprContext>();
}

FlyScriptParser::ExprContext* FlyScriptParser::OrBooleanExprContext::expr(size_t i) {
  return getRuleContext<FlyScriptParser::ExprContext>(i);
}

tree::TerminalNode* FlyScriptParser::OrBooleanExprContext::OrBoolean() {
  return getToken(FlyScriptParser::OrBoolean, 0);
}

FlyScriptParser::OrBooleanExprContext::OrBooleanExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::OrBooleanExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitOrBooleanExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndBooleanExprContext ------------------------------------------------------------------

std::vector<FlyScriptParser::ExprContext *> FlyScriptParser::AndBooleanExprContext::expr() {
  return getRuleContexts<FlyScriptParser::ExprContext>();
}

FlyScriptParser::ExprContext* FlyScriptParser::AndBooleanExprContext::expr(size_t i) {
  return getRuleContext<FlyScriptParser::ExprContext>(i);
}

tree::TerminalNode* FlyScriptParser::AndBooleanExprContext::AndBoolean() {
  return getToken(FlyScriptParser::AndBoolean, 0);
}

FlyScriptParser::AndBooleanExprContext::AndBooleanExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::AndBooleanExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitAndBooleanExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayGetExprContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::ArrayGetExprContext::ID() {
  return getToken(FlyScriptParser::ID, 0);
}

tree::TerminalNode* FlyScriptParser::ArrayGetExprContext::LSquarePar() {
  return getToken(FlyScriptParser::LSquarePar, 0);
}

FlyScriptParser::ExprContext* FlyScriptParser::ArrayGetExprContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}

tree::TerminalNode* FlyScriptParser::ArrayGetExprContext::RSquarePar() {
  return getToken(FlyScriptParser::RSquarePar, 0);
}

FlyScriptParser::ArrayGetExprContext::ArrayGetExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::ArrayGetExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrayGetExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivExprContext ------------------------------------------------------------------

std::vector<FlyScriptParser::ExprContext *> FlyScriptParser::MulDivExprContext::expr() {
  return getRuleContexts<FlyScriptParser::ExprContext>();
}

FlyScriptParser::ExprContext* FlyScriptParser::MulDivExprContext::expr(size_t i) {
  return getRuleContext<FlyScriptParser::ExprContext>(i);
}

tree::TerminalNode* FlyScriptParser::MulDivExprContext::MULTIPLY() {
  return getToken(FlyScriptParser::MULTIPLY, 0);
}

tree::TerminalNode* FlyScriptParser::MulDivExprContext::DIVIDE() {
  return getToken(FlyScriptParser::DIVIDE, 0);
}

FlyScriptParser::MulDivExprContext::MulDivExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::MulDivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitMulDivExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExprContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::IdentifierExprContext::ID() {
  return getToken(FlyScriptParser::ID, 0);
}

FlyScriptParser::IdentifierExprContext::IdentifierExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::IdentifierExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndExprContext ------------------------------------------------------------------

std::vector<FlyScriptParser::ExprContext *> FlyScriptParser::AndExprContext::expr() {
  return getRuleContexts<FlyScriptParser::ExprContext>();
}

FlyScriptParser::ExprContext* FlyScriptParser::AndExprContext::expr(size_t i) {
  return getRuleContext<FlyScriptParser::ExprContext>(i);
}

tree::TerminalNode* FlyScriptParser::AndExprContext::And() {
  return getToken(FlyScriptParser::And, 0);
}

FlyScriptParser::AndExprContext::AndExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}

FlyScriptParser::ExprContext* FlyScriptParser::expr() {
   return expr(0);
}

FlyScriptParser::ExprContext* FlyScriptParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FlyScriptParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  FlyScriptParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, FlyScriptParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(139);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<InvokeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(112);
      match(FlyScriptParser::ID);
      setState(113);
      match(FlyScriptParser::LPAR);
      setState(115);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 219043594240) != 0) {
        setState(114);
        exprList();
      }
      setState(117);
      match(FlyScriptParser::RPAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ArrayGetExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(118);
      match(FlyScriptParser::ID);
      setState(119);
      match(FlyScriptParser::LSquarePar);
      setState(120);
      expr(0);
      setState(121);
      match(FlyScriptParser::RSquarePar);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(123);
      match(FlyScriptParser::NOT);
      setState(124);
      expr(12);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<IdentifierExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(125);
      match(FlyScriptParser::ID);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<IntExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(126);
      match(FlyScriptParser::INT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<StringExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(127);
      match(FlyScriptParser::DQUOTE);
      setState(131);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 3848290697216) != 0) {
        setState(128);
        stringContents();
        setState(133);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(134);
      match(FlyScriptParser::DQUOTE);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ParensExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      match(FlyScriptParser::LPAR);
      setState(136);
      expr(0);
      setState(137);
      match(FlyScriptParser::RPAR);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(165);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(163);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(141);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(142);
          _la = _input->LA(1);
          if (!(_la == FlyScriptParser::MULTIPLY

          || _la == FlyScriptParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(143);
          expr(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusSubExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(144);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(145);
          _la = _input->LA(1);
          if (!(_la == FlyScriptParser::PLUS

          || _la == FlyScriptParser::SUBTRACT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(146);
          expr(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(147);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");

          setState(148);
          match(FlyScriptParser::Or);
          setState(149);
          expr(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(150);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");

          setState(151);
          match(FlyScriptParser::And);
          setState(152);
          expr(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BooleanExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(153);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(154);
          judgeSymbol();
          setState(155);
          expr(8);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<OrBooleanExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(157);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(158);
          match(FlyScriptParser::OrBoolean);
          setState(159);
          expr(7);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AndBooleanExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(160);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(161);
          match(FlyScriptParser::AndBoolean);
          setState(162);
          expr(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(167);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExprListContext ------------------------------------------------------------------

FlyScriptParser::ExprListContext::ExprListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlyScriptParser::ExprContext *> FlyScriptParser::ExprListContext::expr() {
  return getRuleContexts<FlyScriptParser::ExprContext>();
}

FlyScriptParser::ExprContext* FlyScriptParser::ExprListContext::expr(size_t i) {
  return getRuleContext<FlyScriptParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FlyScriptParser::ExprListContext::Comma() {
  return getTokens(FlyScriptParser::Comma);
}

tree::TerminalNode* FlyScriptParser::ExprListContext::Comma(size_t i) {
  return getToken(FlyScriptParser::Comma, i);
}


size_t FlyScriptParser::ExprListContext::getRuleIndex() const {
  return FlyScriptParser::RuleExprList;
}


std::any FlyScriptParser::ExprListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitExprList(this);
  else
    return visitor->visitChildren(this);
}

FlyScriptParser::ExprListContext* FlyScriptParser::exprList() {
  ExprListContext *_localctx = _tracker.createInstance<ExprListContext>(_ctx, getState());
  enterRule(_localctx, 20, FlyScriptParser::RuleExprList);
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
    setState(168);
    expr(0);
    setState(173);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlyScriptParser::Comma) {
      setState(169);
      match(FlyScriptParser::Comma);
      setState(170);
      expr(0);
      setState(175);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContentsContext ------------------------------------------------------------------

FlyScriptParser::StringContentsContext::StringContentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlyScriptParser::StringContentsContext::TEXT() {
  return getToken(FlyScriptParser::TEXT, 0);
}

tree::TerminalNode* FlyScriptParser::StringContentsContext::ESCAPE_SEQUENCE() {
  return getToken(FlyScriptParser::ESCAPE_SEQUENCE, 0);
}

tree::TerminalNode* FlyScriptParser::StringContentsContext::BACKSLASH_PAREN() {
  return getToken(FlyScriptParser::BACKSLASH_PAREN, 0);
}

FlyScriptParser::ExprContext* FlyScriptParser::StringContentsContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}

tree::TerminalNode* FlyScriptParser::StringContentsContext::RPAR() {
  return getToken(FlyScriptParser::RPAR, 0);
}


size_t FlyScriptParser::StringContentsContext::getRuleIndex() const {
  return FlyScriptParser::RuleStringContents;
}


std::any FlyScriptParser::StringContentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitStringContents(this);
  else
    return visitor->visitChildren(this);
}

FlyScriptParser::StringContentsContext* FlyScriptParser::stringContents() {
  StringContentsContext *_localctx = _tracker.createInstance<StringContentsContext>(_ctx, getState());
  enterRule(_localctx, 22, FlyScriptParser::RuleStringContents);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlyScriptParser::TEXT: {
        enterOuterAlt(_localctx, 1);
        setState(176);
        match(FlyScriptParser::TEXT);
        break;
      }

      case FlyScriptParser::ESCAPE_SEQUENCE: {
        enterOuterAlt(_localctx, 2);
        setState(177);
        match(FlyScriptParser::ESCAPE_SEQUENCE);
        break;
      }

      case FlyScriptParser::BACKSLASH_PAREN: {
        enterOuterAlt(_localctx, 3);
        setState(178);
        match(FlyScriptParser::BACKSLASH_PAREN);
        setState(179);
        expr(0);
        setState(180);
        match(FlyScriptParser::RPAR);
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

bool FlyScriptParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FlyScriptParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

void FlyScriptParser::initialize() {
  ::antlr4::internal::call_once(flyscriptparserParserOnceFlag, flyscriptparserParserInitialize);
}
