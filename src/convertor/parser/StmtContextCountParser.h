//
// Created by flying on 2023/2/5.
//

#ifndef FLYLANGUAGE_STMTCONTEXTCOUNTPARSER_H
#define FLYLANGUAGE_STMTCONTEXTCOUNTPARSER_H

#include "StmtContextParser.h"


class StmtContextCountParser : public StmtContextParser {

protected:
    int instructionCount = 0;

public:
    StmtContextCountParser(FlyScriptParser::BlockContext *blockContext, MethodBlock *methodBlock);

    int getInstructionCount() const;

    ~StmtContextCountParser();

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

#endif //FLYLANGUAGE_STMTCONTEXTCOUNTPARSER_H
