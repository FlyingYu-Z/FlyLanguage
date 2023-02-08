
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
      "K_If", "K_Then", "K_Else", "K_While", "K_Break", "K_Return", "Kv_True", 
      "Kv_False", "LCurlyPar", "RCurlyPar", "LSquarePar", "RSquarePar", 
      "PLUS", "SUBTRACT", "MULTIPLY", "DIVIDE", "NOT", "AssignEqual", "JudgeEqual", 
      "NotEqual", "GreaterOrEqual", "Greater", "LesserOrEqual", "Lesser", 
      "OrBoolean", "AndBoolean", "Or", "And", "Comma", "Semicolon", "ID", 
      "LETTER", "INT", "WS", "SL_COMMENT", "DQUOTE", "LPAR", "RPAR", "TEXT", 
      "BACKSLASH_PAREN", "ESCAPE_SEQUENCE", "DQUOTE_IN_STRING"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "IN_STRING"
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
  	4,0,45,296,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,
  	20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,
  	27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,
  	34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,
  	41,2,42,7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,1,0,1,0,1,0,1,0,
  	1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,
  	3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,
  	1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,
  	1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,23,1,24,1,24,
  	1,24,1,25,1,25,1,25,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,29,1,29,1,29,
  	1,30,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,35,
  	5,35,223,8,35,10,35,12,35,226,9,35,1,36,1,36,1,37,4,37,231,8,37,11,37,
  	12,37,232,1,38,4,38,236,8,38,11,38,12,38,237,1,38,1,38,1,39,1,39,1,39,
  	1,39,5,39,246,8,39,10,39,12,39,249,9,39,1,39,1,39,1,39,1,39,1,39,1,39,
  	5,39,257,8,39,10,39,12,39,260,9,39,1,39,1,39,1,39,3,39,265,8,39,1,39,
  	1,39,1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,42,1,43,4,43,280,
  	8,43,11,43,12,43,281,1,44,1,44,1,44,1,44,1,44,1,45,1,45,1,45,1,46,1,46,
  	1,46,1,46,1,46,2,247,258,0,47,2,1,4,2,6,3,8,4,10,5,12,6,14,7,16,8,18,
  	9,20,10,22,11,24,12,26,13,28,14,30,15,32,16,34,17,36,18,38,19,40,20,42,
  	21,44,22,46,23,48,24,50,25,52,26,54,27,56,28,58,29,60,30,62,31,64,32,
  	66,33,68,34,70,35,72,36,74,0,76,37,78,38,80,39,82,40,84,41,86,42,88,43,
  	90,44,92,45,94,0,2,0,1,4,1,0,48,57,2,0,65,90,97,122,3,0,9,10,13,13,32,
  	32,2,0,34,34,92,92,301,0,2,1,0,0,0,0,4,1,0,0,0,0,6,1,0,0,0,0,8,1,0,0,
  	0,0,10,1,0,0,0,0,12,1,0,0,0,0,14,1,0,0,0,0,16,1,0,0,0,0,18,1,0,0,0,0,
  	20,1,0,0,0,0,22,1,0,0,0,0,24,1,0,0,0,0,26,1,0,0,0,0,28,1,0,0,0,0,30,1,
  	0,0,0,0,32,1,0,0,0,0,34,1,0,0,0,0,36,1,0,0,0,0,38,1,0,0,0,0,40,1,0,0,
  	0,0,42,1,0,0,0,0,44,1,0,0,0,0,46,1,0,0,0,0,48,1,0,0,0,0,50,1,0,0,0,0,
  	52,1,0,0,0,0,54,1,0,0,0,0,56,1,0,0,0,0,58,1,0,0,0,0,60,1,0,0,0,0,62,1,
  	0,0,0,0,64,1,0,0,0,0,66,1,0,0,0,0,68,1,0,0,0,0,70,1,0,0,0,0,72,1,0,0,
  	0,0,76,1,0,0,0,0,78,1,0,0,0,0,80,1,0,0,0,0,82,1,0,0,0,0,84,1,0,0,0,0,
  	86,1,0,0,0,1,88,1,0,0,0,1,90,1,0,0,0,1,92,1,0,0,0,1,94,1,0,0,0,2,96,1,
  	0,0,0,4,101,1,0,0,0,6,108,1,0,0,0,8,114,1,0,0,0,10,118,1,0,0,0,12,126,
  	1,0,0,0,14,129,1,0,0,0,16,134,1,0,0,0,18,139,1,0,0,0,20,145,1,0,0,0,22,
  	151,1,0,0,0,24,158,1,0,0,0,26,163,1,0,0,0,28,169,1,0,0,0,30,171,1,0,0,
  	0,32,173,1,0,0,0,34,175,1,0,0,0,36,177,1,0,0,0,38,179,1,0,0,0,40,181,
  	1,0,0,0,42,183,1,0,0,0,44,185,1,0,0,0,46,187,1,0,0,0,48,189,1,0,0,0,50,
  	192,1,0,0,0,52,195,1,0,0,0,54,198,1,0,0,0,56,200,1,0,0,0,58,203,1,0,0,
  	0,60,205,1,0,0,0,62,208,1,0,0,0,64,211,1,0,0,0,66,213,1,0,0,0,68,215,
  	1,0,0,0,70,217,1,0,0,0,72,219,1,0,0,0,74,227,1,0,0,0,76,230,1,0,0,0,78,
  	235,1,0,0,0,80,264,1,0,0,0,82,268,1,0,0,0,84,272,1,0,0,0,86,275,1,0,0,
  	0,88,279,1,0,0,0,90,283,1,0,0,0,92,288,1,0,0,0,94,291,1,0,0,0,96,97,5,
  	118,0,0,97,98,5,111,0,0,98,99,5,105,0,0,99,100,5,100,0,0,100,3,1,0,0,
  	0,101,102,5,115,0,0,102,103,5,116,0,0,103,104,5,114,0,0,104,105,5,105,
  	0,0,105,106,5,110,0,0,106,107,5,103,0,0,107,5,1,0,0,0,108,109,5,102,0,
  	0,109,110,5,108,0,0,110,111,5,111,0,0,111,112,5,97,0,0,112,113,5,116,
  	0,0,113,7,1,0,0,0,114,115,5,105,0,0,115,116,5,110,0,0,116,117,5,116,0,
  	0,117,9,1,0,0,0,118,119,5,98,0,0,119,120,5,111,0,0,120,121,5,111,0,0,
  	121,122,5,108,0,0,122,123,5,101,0,0,123,124,5,97,0,0,124,125,5,110,0,
  	0,125,11,1,0,0,0,126,127,5,105,0,0,127,128,5,102,0,0,128,13,1,0,0,0,129,
  	130,5,116,0,0,130,131,5,104,0,0,131,132,5,101,0,0,132,133,5,110,0,0,133,
  	15,1,0,0,0,134,135,5,101,0,0,135,136,5,108,0,0,136,137,5,115,0,0,137,
  	138,5,101,0,0,138,17,1,0,0,0,139,140,5,119,0,0,140,141,5,104,0,0,141,
  	142,5,105,0,0,142,143,5,108,0,0,143,144,5,101,0,0,144,19,1,0,0,0,145,
  	146,5,98,0,0,146,147,5,114,0,0,147,148,5,101,0,0,148,149,5,97,0,0,149,
  	150,5,107,0,0,150,21,1,0,0,0,151,152,5,114,0,0,152,153,5,101,0,0,153,
  	154,5,116,0,0,154,155,5,117,0,0,155,156,5,114,0,0,156,157,5,110,0,0,157,
  	23,1,0,0,0,158,159,5,116,0,0,159,160,5,114,0,0,160,161,5,117,0,0,161,
  	162,5,101,0,0,162,25,1,0,0,0,163,164,5,102,0,0,164,165,5,97,0,0,165,166,
  	5,108,0,0,166,167,5,115,0,0,167,168,5,101,0,0,168,27,1,0,0,0,169,170,
  	5,123,0,0,170,29,1,0,0,0,171,172,5,125,0,0,172,31,1,0,0,0,173,174,5,91,
  	0,0,174,33,1,0,0,0,175,176,5,93,0,0,176,35,1,0,0,0,177,178,5,43,0,0,178,
  	37,1,0,0,0,179,180,5,45,0,0,180,39,1,0,0,0,181,182,5,42,0,0,182,41,1,
  	0,0,0,183,184,5,47,0,0,184,43,1,0,0,0,185,186,5,33,0,0,186,45,1,0,0,0,
  	187,188,5,61,0,0,188,47,1,0,0,0,189,190,5,61,0,0,190,191,5,61,0,0,191,
  	49,1,0,0,0,192,193,5,33,0,0,193,194,5,61,0,0,194,51,1,0,0,0,195,196,5,
  	62,0,0,196,197,5,61,0,0,197,53,1,0,0,0,198,199,5,62,0,0,199,55,1,0,0,
  	0,200,201,5,60,0,0,201,202,5,61,0,0,202,57,1,0,0,0,203,204,5,60,0,0,204,
  	59,1,0,0,0,205,206,5,124,0,0,206,207,5,124,0,0,207,61,1,0,0,0,208,209,
  	5,38,0,0,209,210,5,38,0,0,210,63,1,0,0,0,211,212,5,124,0,0,212,65,1,0,
  	0,0,213,214,5,38,0,0,214,67,1,0,0,0,215,216,5,44,0,0,216,69,1,0,0,0,217,
  	218,5,59,0,0,218,71,1,0,0,0,219,224,3,74,36,0,220,223,3,74,36,0,221,223,
  	7,0,0,0,222,220,1,0,0,0,222,221,1,0,0,0,223,226,1,0,0,0,224,222,1,0,0,
  	0,224,225,1,0,0,0,225,73,1,0,0,0,226,224,1,0,0,0,227,228,7,1,0,0,228,
  	75,1,0,0,0,229,231,7,0,0,0,230,229,1,0,0,0,231,232,1,0,0,0,232,230,1,
  	0,0,0,232,233,1,0,0,0,233,77,1,0,0,0,234,236,7,2,0,0,235,234,1,0,0,0,
  	236,237,1,0,0,0,237,235,1,0,0,0,237,238,1,0,0,0,238,239,1,0,0,0,239,240,
  	6,38,0,0,240,79,1,0,0,0,241,242,5,47,0,0,242,243,5,47,0,0,243,247,1,0,
  	0,0,244,246,9,0,0,0,245,244,1,0,0,0,246,249,1,0,0,0,247,248,1,0,0,0,247,
  	245,1,0,0,0,248,250,1,0,0,0,249,247,1,0,0,0,250,265,5,10,0,0,251,252,
  	5,47,0,0,252,253,5,42,0,0,253,254,5,42,0,0,254,258,1,0,0,0,255,257,9,
  	0,0,0,256,255,1,0,0,0,257,260,1,0,0,0,258,259,1,0,0,0,258,256,1,0,0,0,
  	259,261,1,0,0,0,260,258,1,0,0,0,261,262,5,42,0,0,262,263,5,42,0,0,263,
  	265,5,47,0,0,264,241,1,0,0,0,264,251,1,0,0,0,265,266,1,0,0,0,266,267,
  	6,39,0,0,267,81,1,0,0,0,268,269,5,34,0,0,269,270,1,0,0,0,270,271,6,40,
  	1,0,271,83,1,0,0,0,272,273,5,40,0,0,273,274,6,41,2,0,274,85,1,0,0,0,275,
  	276,5,41,0,0,276,277,6,42,3,0,277,87,1,0,0,0,278,280,8,3,0,0,279,278,
  	1,0,0,0,280,281,1,0,0,0,281,279,1,0,0,0,281,282,1,0,0,0,282,89,1,0,0,
  	0,283,284,5,92,0,0,284,285,5,40,0,0,285,286,1,0,0,0,286,287,6,44,4,0,
  	287,91,1,0,0,0,288,289,5,92,0,0,289,290,9,0,0,0,290,93,1,0,0,0,291,292,
  	5,34,0,0,292,293,1,0,0,0,293,294,6,46,5,0,294,295,6,46,6,0,295,95,1,0,
  	0,0,10,0,1,222,224,232,237,247,258,264,281,7,6,0,0,5,1,0,1,41,0,1,42,
  	1,1,44,2,7,40,0,4,0,0
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
    case 41: LPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 42: RPARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: BACKSLASH_PARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

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
