
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
      "block", "stmt", "judgeSymbol", "expr", "exprList", "stringContents"
    },
    std::vector<std::string>{
      "", "'void'", "'string'", "'float'", "'int'", "'boolean'", "'if'", 
      "'then'", "'else'", "'while'", "'break'", "'return'", "'true'", "'false'", 
      "'{'", "'}'", "'['", "']'", "'+'", "'-'", "'*'", "'/'", "'!'", "'='", 
      "'=='", "'!='", "'>='", "'>'", "'<='", "'<'", "'||'", "'&&'", "'|'", 
      "'&'", "','", "';'", "", "", "", "", "", "'('", "')'", "", "'\\('"
    },
    std::vector<std::string>{
      "", "Type_void", "Type_string", "Type_float", "Type_int", "Type_boolean", 
      "K_If", "K_Then", "K_Else", "K_While", "K_Break", "K_Return", "Kv_True", 
      "Kv_False", "LCurlyPar", "RCurlyPar", "LSquarePar", "RSquarePar", 
      "PLUS", "SUBTRACT", "MULTIPLY", "DIVIDE", "NOT", "AssignEqual", "JudgeEqual", 
      "NotEqual", "GreaterOrEqual", "Greater", "LesserOrEqual", "Lesser", 
      "OrBoolean", "AndBoolean", "Or", "And", "Comma", "Semicolon", "ID", 
      "INT", "WS", "SL_COMMENT", "DQUOTE", "LPAR", "RPAR", "TEXT", "BACKSLASH_PAREN", 
      "ESCAPE_SEQUENCE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,45,195,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,4,0,28,8,0,11,0,
  	12,0,29,1,1,1,1,1,2,1,2,1,2,1,2,3,2,38,8,2,1,2,1,2,1,3,1,3,1,3,1,3,3,
  	3,46,8,3,1,3,1,3,1,3,1,4,1,4,1,4,5,4,54,8,4,10,4,12,4,57,9,4,1,5,1,5,
  	1,5,1,6,1,6,5,6,64,8,6,10,6,12,6,67,9,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,3,
  	7,76,8,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,87,8,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,99,8,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,3,7,110,8,7,1,8,1,8,1,8,1,8,1,8,1,8,3,8,118,8,8,1,9,1,9,1,9,1,9,3,
  	9,124,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,
  	140,8,9,10,9,12,9,143,9,9,1,9,1,9,1,9,1,9,1,9,3,9,150,8,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,5,9,174,8,9,10,9,12,9,177,9,9,1,10,1,10,1,10,5,10,182,8,10,10,10,
  	12,10,185,9,10,1,11,1,11,1,11,1,11,1,11,1,11,3,11,193,8,11,1,11,0,1,18,
  	12,0,2,4,6,8,10,12,14,16,18,20,22,0,3,1,0,1,5,1,0,20,21,1,0,18,19,224,
  	0,27,1,0,0,0,2,31,1,0,0,0,4,33,1,0,0,0,6,41,1,0,0,0,8,50,1,0,0,0,10,58,
  	1,0,0,0,12,61,1,0,0,0,14,109,1,0,0,0,16,117,1,0,0,0,18,149,1,0,0,0,20,
  	178,1,0,0,0,22,192,1,0,0,0,24,28,3,6,3,0,25,28,3,4,2,0,26,28,3,14,7,0,
  	27,24,1,0,0,0,27,25,1,0,0,0,27,26,1,0,0,0,28,29,1,0,0,0,29,27,1,0,0,0,
  	29,30,1,0,0,0,30,1,1,0,0,0,31,32,7,0,0,0,32,3,1,0,0,0,33,34,3,2,1,0,34,
  	37,5,36,0,0,35,36,5,23,0,0,36,38,3,18,9,0,37,35,1,0,0,0,37,38,1,0,0,0,
  	38,39,1,0,0,0,39,40,5,35,0,0,40,5,1,0,0,0,41,42,3,2,1,0,42,43,5,36,0,
  	0,43,45,5,41,0,0,44,46,3,8,4,0,45,44,1,0,0,0,45,46,1,0,0,0,46,47,1,0,
  	0,0,47,48,5,42,0,0,48,49,3,12,6,0,49,7,1,0,0,0,50,55,3,10,5,0,51,52,5,
  	34,0,0,52,54,3,10,5,0,53,51,1,0,0,0,54,57,1,0,0,0,55,53,1,0,0,0,55,56,
  	1,0,0,0,56,9,1,0,0,0,57,55,1,0,0,0,58,59,3,2,1,0,59,60,5,36,0,0,60,11,
  	1,0,0,0,61,65,5,14,0,0,62,64,3,14,7,0,63,62,1,0,0,0,64,67,1,0,0,0,65,
  	63,1,0,0,0,65,66,1,0,0,0,66,68,1,0,0,0,67,65,1,0,0,0,68,69,5,15,0,0,69,
  	13,1,0,0,0,70,110,3,12,6,0,71,72,3,2,1,0,72,75,5,36,0,0,73,74,5,23,0,
  	0,74,76,3,18,9,0,75,73,1,0,0,0,75,76,1,0,0,0,76,77,1,0,0,0,77,78,5,35,
  	0,0,78,110,1,0,0,0,79,80,5,6,0,0,80,81,5,41,0,0,81,82,3,18,9,0,82,83,
  	5,42,0,0,83,86,3,12,6,0,84,85,5,8,0,0,85,87,3,12,6,0,86,84,1,0,0,0,86,
  	87,1,0,0,0,87,110,1,0,0,0,88,89,5,9,0,0,89,90,5,41,0,0,90,91,3,18,9,0,
  	91,92,5,42,0,0,92,93,3,12,6,0,93,110,1,0,0,0,94,95,5,10,0,0,95,110,5,
  	35,0,0,96,98,5,11,0,0,97,99,3,18,9,0,98,97,1,0,0,0,98,99,1,0,0,0,99,100,
  	1,0,0,0,100,110,5,35,0,0,101,102,3,18,9,0,102,103,5,23,0,0,103,104,3,
  	18,9,0,104,105,5,35,0,0,105,110,1,0,0,0,106,107,3,18,9,0,107,108,5,35,
  	0,0,108,110,1,0,0,0,109,70,1,0,0,0,109,71,1,0,0,0,109,79,1,0,0,0,109,
  	88,1,0,0,0,109,94,1,0,0,0,109,96,1,0,0,0,109,101,1,0,0,0,109,106,1,0,
  	0,0,110,15,1,0,0,0,111,118,5,24,0,0,112,118,5,25,0,0,113,118,5,26,0,0,
  	114,118,5,27,0,0,115,118,5,28,0,0,116,118,5,29,0,0,117,111,1,0,0,0,117,
  	112,1,0,0,0,117,113,1,0,0,0,117,114,1,0,0,0,117,115,1,0,0,0,117,116,1,
  	0,0,0,118,17,1,0,0,0,119,120,6,9,-1,0,120,121,5,36,0,0,121,123,5,41,0,
  	0,122,124,3,20,10,0,123,122,1,0,0,0,123,124,1,0,0,0,124,125,1,0,0,0,125,
  	150,5,42,0,0,126,127,5,36,0,0,127,128,5,16,0,0,128,129,3,18,9,0,129,130,
  	5,17,0,0,130,150,1,0,0,0,131,132,5,22,0,0,132,150,3,18,9,14,133,150,5,
  	36,0,0,134,150,5,37,0,0,135,150,5,12,0,0,136,150,5,13,0,0,137,141,5,40,
  	0,0,138,140,3,22,11,0,139,138,1,0,0,0,140,143,1,0,0,0,141,139,1,0,0,0,
  	141,142,1,0,0,0,142,144,1,0,0,0,143,141,1,0,0,0,144,150,5,40,0,0,145,
  	146,5,41,0,0,146,147,3,18,9,0,147,148,5,42,0,0,148,150,1,0,0,0,149,119,
  	1,0,0,0,149,126,1,0,0,0,149,131,1,0,0,0,149,133,1,0,0,0,149,134,1,0,0,
  	0,149,135,1,0,0,0,149,136,1,0,0,0,149,137,1,0,0,0,149,145,1,0,0,0,150,
  	175,1,0,0,0,151,152,10,13,0,0,152,153,7,1,0,0,153,174,3,18,9,14,154,155,
  	10,12,0,0,155,156,7,2,0,0,156,174,3,18,9,13,157,158,10,11,0,0,158,159,
  	5,32,0,0,159,174,3,18,9,12,160,161,10,10,0,0,161,162,5,33,0,0,162,174,
  	3,18,9,11,163,164,10,9,0,0,164,165,3,16,8,0,165,166,3,18,9,10,166,174,
  	1,0,0,0,167,168,10,8,0,0,168,169,5,30,0,0,169,174,3,18,9,9,170,171,10,
  	7,0,0,171,172,5,31,0,0,172,174,3,18,9,8,173,151,1,0,0,0,173,154,1,0,0,
  	0,173,157,1,0,0,0,173,160,1,0,0,0,173,163,1,0,0,0,173,167,1,0,0,0,173,
  	170,1,0,0,0,174,177,1,0,0,0,175,173,1,0,0,0,175,176,1,0,0,0,176,19,1,
  	0,0,0,177,175,1,0,0,0,178,183,3,18,9,0,179,180,5,34,0,0,180,182,3,18,
  	9,0,181,179,1,0,0,0,182,185,1,0,0,0,183,181,1,0,0,0,183,184,1,0,0,0,184,
  	21,1,0,0,0,185,183,1,0,0,0,186,193,5,43,0,0,187,193,5,45,0,0,188,189,
  	5,44,0,0,189,190,3,18,9,0,190,191,5,42,0,0,191,193,1,0,0,0,192,186,1,
  	0,0,0,192,187,1,0,0,0,192,188,1,0,0,0,193,23,1,0,0,0,18,27,29,37,45,55,
  	65,75,86,98,109,117,123,141,149,173,175,183,192
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

std::vector<FlyScriptParser::StmtContext *> FlyScriptParser::FileContext::stmt() {
  return getRuleContexts<FlyScriptParser::StmtContext>();
}

FlyScriptParser::StmtContext* FlyScriptParser::FileContext::stmt(size_t i) {
  return getRuleContext<FlyScriptParser::StmtContext>(i);
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
        stmt();
        break;
      }

      default:
        break;
      }
      setState(29); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3504697540222) != 0);
   
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

std::vector<FlyScriptParser::StmtContext *> FlyScriptParser::BlockContext::stmt() {
  return getRuleContexts<FlyScriptParser::StmtContext>();
}

FlyScriptParser::StmtContext* FlyScriptParser::BlockContext::stmt(size_t i) {
  return getRuleContext<FlyScriptParser::StmtContext>(i);
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
      ((1ULL << _la) & 3504697540222) != 0) {
      setState(62);
      stmt();
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

//----------------- StmtContext ------------------------------------------------------------------

FlyScriptParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FlyScriptParser::StmtContext::getRuleIndex() const {
  return FlyScriptParser::RuleStmt;
}

void FlyScriptParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- InvokeStmtContext ------------------------------------------------------------------

FlyScriptParser::ExprContext* FlyScriptParser::InvokeStmtContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}

tree::TerminalNode* FlyScriptParser::InvokeStmtContext::Semicolon() {
  return getToken(FlyScriptParser::Semicolon, 0);
}

FlyScriptParser::InvokeStmtContext::InvokeStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::InvokeStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitInvokeStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::WhileStmtContext::K_While() {
  return getToken(FlyScriptParser::K_While, 0);
}

tree::TerminalNode* FlyScriptParser::WhileStmtContext::LPAR() {
  return getToken(FlyScriptParser::LPAR, 0);
}

FlyScriptParser::ExprContext* FlyScriptParser::WhileStmtContext::expr() {
  return getRuleContext<FlyScriptParser::ExprContext>(0);
}

tree::TerminalNode* FlyScriptParser::WhileStmtContext::RPAR() {
  return getToken(FlyScriptParser::RPAR, 0);
}

FlyScriptParser::BlockContext* FlyScriptParser::WhileStmtContext::block() {
  return getRuleContext<FlyScriptParser::BlockContext>(0);
}

FlyScriptParser::WhileStmtContext::WhileStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CodeBlockContext ------------------------------------------------------------------

FlyScriptParser::BlockContext* FlyScriptParser::CodeBlockContext::block() {
  return getRuleContext<FlyScriptParser::BlockContext>(0);
}

FlyScriptParser::CodeBlockContext::CodeBlockContext(StmtContext *ctx) { copyFrom(ctx); }


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

FlyScriptParser::IfElseStmtContext::IfElseStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::IfElseStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitIfElseStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::BreakStmtContext::K_Break() {
  return getToken(FlyScriptParser::K_Break, 0);
}

tree::TerminalNode* FlyScriptParser::BreakStmtContext::Semicolon() {
  return getToken(FlyScriptParser::Semicolon, 0);
}

FlyScriptParser::BreakStmtContext::BreakStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitBreakStmt(this);
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

FlyScriptParser::AssignStmtContext::AssignStmtContext(StmtContext *ctx) { copyFrom(ctx); }


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

FlyScriptParser::ReturnStmtContext::ReturnStmtContext(StmtContext *ctx) { copyFrom(ctx); }


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

FlyScriptParser::VarStmtContext::VarStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::VarStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitVarStmt(this);
  else
    return visitor->visitChildren(this);
}
FlyScriptParser::StmtContext* FlyScriptParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 14, FlyScriptParser::RuleStmt);
  size_t _la = 0;

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
      _localctx = _tracker.createInstance<FlyScriptParser::WhileStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(88);
      match(FlyScriptParser::K_While);
      setState(89);
      match(FlyScriptParser::LPAR);
      setState(90);
      expr(0);
      setState(91);
      match(FlyScriptParser::RPAR);
      setState(92);
      block();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<FlyScriptParser::BreakStmtContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(94);
      match(FlyScriptParser::K_Break);
      setState(95);
      match(FlyScriptParser::Semicolon);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<FlyScriptParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(96);
      match(FlyScriptParser::K_Return);
      setState(98);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 3504697520128) != 0) {
        setState(97);
        expr(0);
      }
      setState(100);
      match(FlyScriptParser::Semicolon);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<FlyScriptParser::AssignStmtContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(101);
      expr(0);
      setState(102);
      match(FlyScriptParser::AssignEqual);
      setState(103);
      expr(0);
      setState(104);
      match(FlyScriptParser::Semicolon);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<FlyScriptParser::InvokeStmtContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(106);
      expr(0);
      setState(107);
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
    setState(117);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlyScriptParser::JudgeEqual: {
        _localctx = _tracker.createInstance<FlyScriptParser::JudgeEqualSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(111);
        match(FlyScriptParser::JudgeEqual);
        break;
      }

      case FlyScriptParser::NotEqual: {
        _localctx = _tracker.createInstance<FlyScriptParser::NotEqualSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(112);
        match(FlyScriptParser::NotEqual);
        break;
      }

      case FlyScriptParser::GreaterOrEqual: {
        _localctx = _tracker.createInstance<FlyScriptParser::GreaterOrEqualSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(113);
        match(FlyScriptParser::GreaterOrEqual);
        break;
      }

      case FlyScriptParser::Greater: {
        _localctx = _tracker.createInstance<FlyScriptParser::GreaterSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(114);
        match(FlyScriptParser::Greater);
        break;
      }

      case FlyScriptParser::LesserOrEqual: {
        _localctx = _tracker.createInstance<FlyScriptParser::LesserOrEqualSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(115);
        match(FlyScriptParser::LesserOrEqual);
        break;
      }

      case FlyScriptParser::Lesser: {
        _localctx = _tracker.createInstance<FlyScriptParser::LesserSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(116);
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
//----------------- BooleanTrueExprContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::BooleanTrueExprContext::Kv_True() {
  return getToken(FlyScriptParser::Kv_True, 0);
}

FlyScriptParser::BooleanTrueExprContext::BooleanTrueExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::BooleanTrueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitBooleanTrueExpr(this);
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
//----------------- BooleanFalseExprContext ------------------------------------------------------------------

tree::TerminalNode* FlyScriptParser::BooleanFalseExprContext::Kv_False() {
  return getToken(FlyScriptParser::Kv_False, 0);
}

FlyScriptParser::BooleanFalseExprContext::BooleanFalseExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any FlyScriptParser::BooleanFalseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlyScriptParserVisitor*>(visitor))
    return parserVisitor->visitBooleanFalseExpr(this);
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
    setState(149);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<InvokeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(120);
      match(FlyScriptParser::ID);
      setState(121);
      match(FlyScriptParser::LPAR);
      setState(123);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 3504697520128) != 0) {
        setState(122);
        exprList();
      }
      setState(125);
      match(FlyScriptParser::RPAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ArrayGetExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(126);
      match(FlyScriptParser::ID);
      setState(127);
      match(FlyScriptParser::LSquarePar);
      setState(128);
      expr(0);
      setState(129);
      match(FlyScriptParser::RSquarePar);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(131);
      match(FlyScriptParser::NOT);
      setState(132);
      expr(14);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<IdentifierExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(133);
      match(FlyScriptParser::ID);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<IntExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(134);
      match(FlyScriptParser::INT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<BooleanTrueExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      match(FlyScriptParser::Kv_True);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<BooleanFalseExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(136);
      match(FlyScriptParser::Kv_False);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<StringExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(137);
      match(FlyScriptParser::DQUOTE);
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 61572651155456) != 0) {
        setState(138);
        stringContents();
        setState(143);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(144);
      match(FlyScriptParser::DQUOTE);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ParensExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(145);
      match(FlyScriptParser::LPAR);
      setState(146);
      expr(0);
      setState(147);
      match(FlyScriptParser::RPAR);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(175);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(173);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(151);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(152);
          _la = _input->LA(1);
          if (!(_la == FlyScriptParser::MULTIPLY

          || _la == FlyScriptParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(153);
          expr(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusSubExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(154);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(155);
          _la = _input->LA(1);
          if (!(_la == FlyScriptParser::PLUS

          || _la == FlyScriptParser::SUBTRACT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(156);
          expr(13);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(157);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");

          setState(158);
          match(FlyScriptParser::Or);
          setState(159);
          expr(12);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(160);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");

          setState(161);
          match(FlyScriptParser::And);
          setState(162);
          expr(11);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BooleanExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(163);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(164);
          judgeSymbol();
          setState(165);
          expr(10);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<OrBooleanExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(167);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(168);
          match(FlyScriptParser::OrBoolean);
          setState(169);
          expr(9);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AndBooleanExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(170);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(171);
          match(FlyScriptParser::AndBoolean);
          setState(172);
          expr(8);
          break;
        }

        default:
          break;
        } 
      }
      setState(177);
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
    setState(178);
    expr(0);
    setState(183);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlyScriptParser::Comma) {
      setState(179);
      match(FlyScriptParser::Comma);
      setState(180);
      expr(0);
      setState(185);
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
    setState(192);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlyScriptParser::TEXT: {
        enterOuterAlt(_localctx, 1);
        setState(186);
        match(FlyScriptParser::TEXT);
        break;
      }

      case FlyScriptParser::ESCAPE_SEQUENCE: {
        enterOuterAlt(_localctx, 2);
        setState(187);
        match(FlyScriptParser::ESCAPE_SEQUENCE);
        break;
      }

      case FlyScriptParser::BACKSLASH_PAREN: {
        enterOuterAlt(_localctx, 3);
        setState(188);
        match(FlyScriptParser::BACKSLASH_PAREN);
        setState(189);
        expr(0);
        setState(190);
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
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 10);
    case 4: return precpred(_ctx, 9);
    case 5: return precpred(_ctx, 8);
    case 6: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

void FlyScriptParser::initialize() {
  ::antlr4::internal::call_once(flyscriptparserParserOnceFlag, flyscriptparserParserInitialize);
}
