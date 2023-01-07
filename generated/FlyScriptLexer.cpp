
// Generated from FlyScriptLexer.g4 by ANTLR 4.11.1


#include "FlyScriptLexer.h"


using namespace antlr4;

using namespace beingyi;


using namespace antlr4;

namespace {

struct FlyScriptLexerStaticData final {
  FlyScriptLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FlyScriptLexerStaticData(const FlyScriptLexerStaticData&) = delete;
  FlyScriptLexerStaticData(FlyScriptLexerStaticData&&) = delete;
  FlyScriptLexerStaticData& operator=(const FlyScriptLexerStaticData&) = delete;
  FlyScriptLexerStaticData& operator=(FlyScriptLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag flyscriptlexerLexerOnceFlag;
FlyScriptLexerStaticData *flyscriptlexerLexerStaticData = nullptr;

void flyscriptlexerLexerInitialize() {
  assert(flyscriptlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<FlyScriptLexerStaticData>(
    std::vector<std::string>{
      "Type_void", "Type_string", "Type_float", "Type_int", "Type_boolean", 
      "K_If", "K_Then", "K_Else", "K_Return", "LCurlyPar", "RCurlyPar", 
      "LSquarePar", "RSquarePar", "PLUS", "SUBTRACT", "MULTIPLY", "DIVIDE", 
      "NOT", "AssignEqual", "JudgeEqual", "NotEqual", "GreaterOrEqual", 
      "Greater", "LesserOrEqual", "Lesser", "OrBoolean", "AndBoolean", "Or", 
      "And", "Comma", "Semicolon", "ID", "LETTER", "INT", "WS", "SL_COMMENT", 
      "DQUOTE", "LPAR", "RPAR", "TEXT", "BACKSLASH_PAREN", "ESCAPE_SEQUENCE", 
      "DQUOTE_IN_STRING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "IN_STRING"
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
  	4,0,41,251,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,
  	20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,
  	27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,
  	34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,
  	41,2,42,7,42,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,
  	5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,
  	15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,20,1,21,1,
  	21,1,21,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,
  	26,1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,31,5,31,192,8,
  	31,10,31,12,31,195,9,31,1,32,1,32,1,33,4,33,200,8,33,11,33,12,33,201,
  	1,34,4,34,205,8,34,11,34,12,34,206,1,34,1,34,1,35,1,35,1,35,1,35,5,35,
  	215,8,35,10,35,12,35,218,9,35,1,35,1,35,1,35,1,35,1,36,1,36,1,36,1,36,
  	1,37,1,37,1,37,1,38,1,38,1,38,1,39,4,39,235,8,39,11,39,12,39,236,1,40,
  	1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,42,1,42,1,42,1,216,0,43,
  	2,1,4,2,6,3,8,4,10,5,12,6,14,7,16,8,18,9,20,10,22,11,24,12,26,13,28,14,
  	30,15,32,16,34,17,36,18,38,19,40,20,42,21,44,22,46,23,48,24,50,25,52,
  	26,54,27,56,28,58,29,60,30,62,31,64,32,66,0,68,33,70,34,72,35,74,36,76,
  	37,78,38,80,39,82,40,84,41,86,0,2,0,1,4,1,0,48,57,2,0,65,90,97,122,3,
  	0,9,10,13,13,32,32,2,0,34,34,92,92,254,0,2,1,0,0,0,0,4,1,0,0,0,0,6,1,
  	0,0,0,0,8,1,0,0,0,0,10,1,0,0,0,0,12,1,0,0,0,0,14,1,0,0,0,0,16,1,0,0,0,
  	0,18,1,0,0,0,0,20,1,0,0,0,0,22,1,0,0,0,0,24,1,0,0,0,0,26,1,0,0,0,0,28,
  	1,0,0,0,0,30,1,0,0,0,0,32,1,0,0,0,0,34,1,0,0,0,0,36,1,0,0,0,0,38,1,0,
  	0,0,0,40,1,0,0,0,0,42,1,0,0,0,0,44,1,0,0,0,0,46,1,0,0,0,0,48,1,0,0,0,
  	0,50,1,0,0,0,0,52,1,0,0,0,0,54,1,0,0,0,0,56,1,0,0,0,0,58,1,0,0,0,0,60,
  	1,0,0,0,0,62,1,0,0,0,0,64,1,0,0,0,0,68,1,0,0,0,0,70,1,0,0,0,0,72,1,0,
  	0,0,0,74,1,0,0,0,0,76,1,0,0,0,0,78,1,0,0,0,1,80,1,0,0,0,1,82,1,0,0,0,
  	1,84,1,0,0,0,1,86,1,0,0,0,2,88,1,0,0,0,4,93,1,0,0,0,6,100,1,0,0,0,8,106,
  	1,0,0,0,10,110,1,0,0,0,12,118,1,0,0,0,14,121,1,0,0,0,16,126,1,0,0,0,18,
  	131,1,0,0,0,20,138,1,0,0,0,22,140,1,0,0,0,24,142,1,0,0,0,26,144,1,0,0,
  	0,28,146,1,0,0,0,30,148,1,0,0,0,32,150,1,0,0,0,34,152,1,0,0,0,36,154,
  	1,0,0,0,38,156,1,0,0,0,40,158,1,0,0,0,42,161,1,0,0,0,44,164,1,0,0,0,46,
  	167,1,0,0,0,48,169,1,0,0,0,50,172,1,0,0,0,52,174,1,0,0,0,54,177,1,0,0,
  	0,56,180,1,0,0,0,58,182,1,0,0,0,60,184,1,0,0,0,62,186,1,0,0,0,64,188,
  	1,0,0,0,66,196,1,0,0,0,68,199,1,0,0,0,70,204,1,0,0,0,72,210,1,0,0,0,74,
  	223,1,0,0,0,76,227,1,0,0,0,78,230,1,0,0,0,80,234,1,0,0,0,82,238,1,0,0,
  	0,84,243,1,0,0,0,86,246,1,0,0,0,88,89,5,118,0,0,89,90,5,111,0,0,90,91,
  	5,105,0,0,91,92,5,100,0,0,92,3,1,0,0,0,93,94,5,115,0,0,94,95,5,116,0,
  	0,95,96,5,114,0,0,96,97,5,105,0,0,97,98,5,110,0,0,98,99,5,103,0,0,99,
  	5,1,0,0,0,100,101,5,102,0,0,101,102,5,108,0,0,102,103,5,111,0,0,103,104,
  	5,97,0,0,104,105,5,116,0,0,105,7,1,0,0,0,106,107,5,105,0,0,107,108,5,
  	110,0,0,108,109,5,116,0,0,109,9,1,0,0,0,110,111,5,98,0,0,111,112,5,111,
  	0,0,112,113,5,111,0,0,113,114,5,108,0,0,114,115,5,101,0,0,115,116,5,97,
  	0,0,116,117,5,110,0,0,117,11,1,0,0,0,118,119,5,105,0,0,119,120,5,102,
  	0,0,120,13,1,0,0,0,121,122,5,116,0,0,122,123,5,104,0,0,123,124,5,101,
  	0,0,124,125,5,110,0,0,125,15,1,0,0,0,126,127,5,101,0,0,127,128,5,108,
  	0,0,128,129,5,115,0,0,129,130,5,101,0,0,130,17,1,0,0,0,131,132,5,114,
  	0,0,132,133,5,101,0,0,133,134,5,116,0,0,134,135,5,117,0,0,135,136,5,114,
  	0,0,136,137,5,110,0,0,137,19,1,0,0,0,138,139,5,123,0,0,139,21,1,0,0,0,
  	140,141,5,125,0,0,141,23,1,0,0,0,142,143,5,91,0,0,143,25,1,0,0,0,144,
  	145,5,93,0,0,145,27,1,0,0,0,146,147,5,43,0,0,147,29,1,0,0,0,148,149,5,
  	45,0,0,149,31,1,0,0,0,150,151,5,42,0,0,151,33,1,0,0,0,152,153,5,47,0,
  	0,153,35,1,0,0,0,154,155,5,33,0,0,155,37,1,0,0,0,156,157,5,61,0,0,157,
  	39,1,0,0,0,158,159,5,61,0,0,159,160,5,61,0,0,160,41,1,0,0,0,161,162,5,
  	33,0,0,162,163,5,61,0,0,163,43,1,0,0,0,164,165,5,62,0,0,165,166,5,61,
  	0,0,166,45,1,0,0,0,167,168,5,62,0,0,168,47,1,0,0,0,169,170,5,60,0,0,170,
  	171,5,61,0,0,171,49,1,0,0,0,172,173,5,60,0,0,173,51,1,0,0,0,174,175,5,
  	124,0,0,175,176,5,124,0,0,176,53,1,0,0,0,177,178,5,38,0,0,178,179,5,38,
  	0,0,179,55,1,0,0,0,180,181,5,124,0,0,181,57,1,0,0,0,182,183,5,38,0,0,
  	183,59,1,0,0,0,184,185,5,44,0,0,185,61,1,0,0,0,186,187,5,59,0,0,187,63,
  	1,0,0,0,188,193,3,66,32,0,189,192,3,66,32,0,190,192,7,0,0,0,191,189,1,
  	0,0,0,191,190,1,0,0,0,192,195,1,0,0,0,193,191,1,0,0,0,193,194,1,0,0,0,
  	194,65,1,0,0,0,195,193,1,0,0,0,196,197,7,1,0,0,197,67,1,0,0,0,198,200,
  	7,0,0,0,199,198,1,0,0,0,200,201,1,0,0,0,201,199,1,0,0,0,201,202,1,0,0,
  	0,202,69,1,0,0,0,203,205,7,2,0,0,204,203,1,0,0,0,205,206,1,0,0,0,206,
  	204,1,0,0,0,206,207,1,0,0,0,207,208,1,0,0,0,208,209,6,34,0,0,209,71,1,
  	0,0,0,210,211,5,47,0,0,211,212,5,47,0,0,212,216,1,0,0,0,213,215,9,0,0,
  	0,214,213,1,0,0,0,215,218,1,0,0,0,216,217,1,0,0,0,216,214,1,0,0,0,217,
  	219,1,0,0,0,218,216,1,0,0,0,219,220,5,10,0,0,220,221,1,0,0,0,221,222,
  	6,35,0,0,222,73,1,0,0,0,223,224,5,34,0,0,224,225,1,0,0,0,225,226,6,36,
  	1,0,226,75,1,0,0,0,227,228,5,40,0,0,228,229,6,37,2,0,229,77,1,0,0,0,230,
  	231,5,41,0,0,231,232,6,38,3,0,232,79,1,0,0,0,233,235,8,3,0,0,234,233,
  	1,0,0,0,235,236,1,0,0,0,236,234,1,0,0,0,236,237,1,0,0,0,237,81,1,0,0,
  	0,238,239,5,92,0,0,239,240,5,40,0,0,240,241,1,0,0,0,241,242,6,40,4,0,
  	242,83,1,0,0,0,243,244,5,92,0,0,244,245,9,0,0,0,245,85,1,0,0,0,246,247,
  	5,34,0,0,247,248,1,0,0,0,248,249,6,42,5,0,249,250,6,42,6,0,250,87,1,0,
  	0,0,8,0,1,191,193,201,206,216,236,7,6,0,0,5,1,0,1,37,0,1,38,1,1,40,2,
  	7,36,0,4,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  flyscriptlexerLexerStaticData = staticData.release();
}

}

FlyScriptLexer::FlyScriptLexer(CharStream *input) : Lexer(input) {
  FlyScriptLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *flyscriptlexerLexerStaticData->atn, flyscriptlexerLexerStaticData->decisionToDFA, flyscriptlexerLexerStaticData->sharedContextCache);
}

FlyScriptLexer::~FlyScriptLexer() {
  delete _interpreter;
}

std::string FlyScriptLexer::getGrammarFileName() const {
  return "FlyScriptLexer.g4";
}

const std::vector<std::string>& FlyScriptLexer::getRuleNames() const {
  return flyscriptlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& FlyScriptLexer::getChannelNames() const {
  return flyscriptlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& FlyScriptLexer::getModeNames() const {
  return flyscriptlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& FlyScriptLexer::getVocabulary() const {
  return flyscriptlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FlyScriptLexer::getSerializedATN() const {
  return flyscriptlexerLexerStaticData->serializedATN;
}

const atn::ATN& FlyScriptLexer::getATN() const {
  return *flyscriptlexerLexerStaticData->atn;
}


void FlyScriptLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 37: LPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 38: RPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 40: BACKSLASH_PARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void FlyScriptLexer::LPARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: 
        nesting++;
        pushMode(DEFAULT_MODE);
     break;

  default:
    break;
  }
}

void FlyScriptLexer::RPARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1: 
        if (nesting > 0) {
            nesting--;
            popMode();
        }
     break;

  default:
    break;
  }
}

void FlyScriptLexer::BACKSLASH_PARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: 
        nesting++;
        pushMode(DEFAULT_MODE);
     break;

  default:
    break;
  }
}



void FlyScriptLexer::initialize() {
  ::antlr4::internal::call_once(flyscriptlexerLexerOnceFlag, flyscriptlexerLexerInitialize);
}
