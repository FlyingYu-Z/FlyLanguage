//
// Created by flying on 2023/2/5.
//

#ifndef FLYLANGUAGE_STMTCONTEXTINSTRUCTIONPARSER_H
#define FLYLANGUAGE_STMTCONTEXTINSTRUCTIONPARSER_H

#include "StmtContextParser.h"
#include "StmtContextCountParser.h"

class StmtContextInstructionParser : public StmtContextParser {

public:
    StmtContextInstructionParser(FlyScriptParser::BlockContext *blockContext, MethodBlock *methodBlock);

    ~StmtContextInstructionParser();

private:
    void onVisitFieldContext(FlyScriptParser::FieldContext *fieldContext);

    void onVisitVarStmtContext(FlyScriptParser::VarStmtContext *varStmtContext);

    void onVisitAssignStmtContext(FlyScriptParser::AssignStmtContext *assignStmtContext);

    void onVisitInvokeStmtContext(FlyScriptParser::InvokeStmtContext *invokeStmtContext);

    void onVisitIfElseStmtContext(FlyScriptParser::IfElseStmtContext *ifElseStmtContext);

    void onVisitWhileStmtContext(FlyScriptParser::WhileStmtContext *whileStmtContext);

    void onVisitBreakStmtContext(FlyScriptParser::BreakStmtContext *breakStmtContext);

    void onVisitReturnStmtContext(FlyScriptParser::ReturnStmtContext *returnStmtContext);

};

#endif //FLYLANGUAGE_STMTCONTEXTINSTRUCTIONPARSER_H
