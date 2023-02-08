//
// Created by flying on 2023/2/5.
//
#include "StmtContextCountParser.h"

StmtContextCountParser::StmtContextCountParser(FlyScriptParser::BlockContext *blockContext, MethodBlock *methodBlock)
        : StmtContextParser(
        blockContext, methodBlock) {

}

int StmtContextCountParser::getInstructionCount() const {
    return instructionCount;
}

StmtContextCountParser::~StmtContextCountParser() {

}

void StmtContextCountParser::onVisitFieldContext(FlyScriptParser::FieldContext *fieldContext) {
    StmtContextParser::onVisitFieldContext(fieldContext);
}

void StmtContextCountParser::onVisitVarStmtContext(FlyScriptParser::VarStmtContext *varStmtContext) {
    StmtContextParser::onVisitVarStmtContext(varStmtContext);
}

void StmtContextCountParser::onVisitAssignStmtContext(FlyScriptParser::AssignStmtContext *assignStmtContext) {
    StmtContextParser::onVisitAssignStmtContext(assignStmtContext);
}

void StmtContextCountParser::onVisitInvokeStmtContext(FlyScriptParser::InvokeStmtContext *invokeStmtContext) {
    StmtContextParser::onVisitInvokeStmtContext(invokeStmtContext);
}

void StmtContextCountParser::onVisitIfElseStmtContext(FlyScriptParser::IfElseStmtContext *ifElseStmtContext) {
    StmtContextParser::onVisitIfElseStmtContext(ifElseStmtContext);
}

void StmtContextCountParser::onVisitWhileStmtContext(FlyScriptParser::WhileStmtContext *whileStmtContext) {
    StmtContextParser::onVisitWhileStmtContext(whileStmtContext);
}

void StmtContextCountParser::onVisitBreakStmtContext(FlyScriptParser::BreakStmtContext *breakStmtContext) {
    StmtContextParser::onVisitBreakStmtContext(breakStmtContext);
}

void StmtContextCountParser::onVisitReturnStmtContext(FlyScriptParser::ReturnStmtContext *returnStmtContext) {
    StmtContextParser::onVisitReturnStmtContext(returnStmtContext);
}