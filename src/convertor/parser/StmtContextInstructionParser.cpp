//
// Created by flying on 2023/2/5.
//
#include "StmtContextInstructionParser.h"

StmtContextInstructionParser::StmtContextInstructionParser(FlyScriptParser::BlockContext *blockContext, MethodBlock *methodBlock)
        : StmtContextParser(
        blockContext, methodBlock) {

}

StmtContextInstructionParser::~StmtContextInstructionParser(){

}

void StmtContextInstructionParser::onVisitFieldContext(FlyScriptParser::FieldContext *fieldContext) {
    StmtContextParser::onVisitFieldContext(fieldContext);
}

void StmtContextInstructionParser::onVisitVarStmtContext(FlyScriptParser::VarStmtContext *varStmtContext) {
    StmtContextParser::onVisitVarStmtContext(varStmtContext);
}

void StmtContextInstructionParser::onVisitAssignStmtContext(FlyScriptParser::AssignStmtContext *assignStmtContext) {
    StmtContextParser::onVisitAssignStmtContext(assignStmtContext);
}

void StmtContextInstructionParser::onVisitInvokeStmtContext(FlyScriptParser::InvokeStmtContext *invokeStmtContext) {
    StmtContextParser::onVisitInvokeStmtContext(invokeStmtContext);
}

void StmtContextInstructionParser::onVisitIfElseStmtContext(FlyScriptParser::IfElseStmtContext *ifElseStmtContext) {
    StmtContextParser::onVisitIfElseStmtContext(ifElseStmtContext);
}

void StmtContextInstructionParser::onVisitWhileStmtContext(FlyScriptParser::WhileStmtContext *whileStmtContext) {
    StmtContextParser::onVisitWhileStmtContext(whileStmtContext);
}

void StmtContextInstructionParser::onVisitBreakStmtContext(FlyScriptParser::BreakStmtContext *breakStmtContext) {
    StmtContextParser::onVisitBreakStmtContext(breakStmtContext);
}

void StmtContextInstructionParser::onVisitReturnStmtContext(FlyScriptParser::ReturnStmtContext *returnStmtContext) {
    StmtContextParser::onVisitReturnStmtContext(returnStmtContext);
}

