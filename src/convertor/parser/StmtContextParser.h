//
// Created by flying on 2023/2/5.
//

#ifndef FLYLANGUAGE_STMTCONTEXTPARSER_H
#define FLYLANGUAGE_STMTCONTEXTPARSER_H

#include "Ast2IrConvertor.h"

//#include "antlr4-runtime.h"
//#include "FlyScriptLexer.h"
//#include "FlyScriptParser.h"

using namespace beingyi;
using namespace antlr4;
using namespace antlr4::tree;


class StmtContextParser {

protected:
    FlyScriptParser::BlockContext *blockContext;
    MethodBlock *methodBlock;
    vector<ParseTree *> rawStmtList = vector<ParseTree *>();

public:
    StmtContextParser(FlyScriptParser::BlockContext *blockContext, MethodBlock *methodBlock) : blockContext(
            blockContext), methodBlock(methodBlock) {

    }

    virtual ~StmtContextParser();

    virtual void onVisitFieldContext(FlyScriptParser::FieldContext *fieldContext);

    virtual void onVisitVarStmtContext(FlyScriptParser::VarStmtContext *varStmtContext);

    virtual void onVisitAssignStmtContext(FlyScriptParser::AssignStmtContext *assignStmtContext);

    virtual void onVisitInvokeStmtContext(FlyScriptParser::InvokeStmtContext *invokeStmtContext);

    virtual void onVisitIfElseStmtContext(FlyScriptParser::IfElseStmtContext *ifElseStmtContext);

    virtual void onVisitWhileStmtContext(FlyScriptParser::WhileStmtContext *whileStmtContext);

    virtual void onVisitBreakStmtContext(FlyScriptParser::BreakStmtContext *breakStmtContext);

    virtual void onVisitReturnStmtContext(FlyScriptParser::ReturnStmtContext *returnStmtContext);

    static void parse(StmtContextParser *stmtContextParser){
        for (ParseTree *child: stmtContextParser->blockContext->children) {
            if (FlyScriptParser::StmtContext *stmtContext = dynamic_cast<FlyScriptParser::StmtContext *>(child)) {
                stmtContextParser->rawStmtList.push_back(stmtContext);
            }
        }
        for (ParseTree *stmtContext: stmtContextParser->rawStmtList) {
            if (FlyScriptParser::FieldContext *fieldContext = dynamic_cast<FlyScriptParser::FieldContext *>(stmtContext)) {
                stmtContextParser->onVisitFieldContext(fieldContext);
            } else if (FlyScriptParser::VarStmtContext *varStmtContext = dynamic_cast<FlyScriptParser::VarStmtContext *>(stmtContext)) {
                stmtContextParser->onVisitVarStmtContext(varStmtContext);
            } else if (FlyScriptParser::AssignStmtContext *assignStmtContext = dynamic_cast<FlyScriptParser::AssignStmtContext *>(stmtContext)) {
                stmtContextParser->onVisitAssignStmtContext(assignStmtContext);
            } else if (FlyScriptParser::InvokeStmtContext *invokeStmtContext = dynamic_cast<FlyScriptParser::InvokeStmtContext *>(stmtContext)) {
                stmtContextParser->onVisitInvokeStmtContext(invokeStmtContext);
            } else if (FlyScriptParser::IfElseStmtContext *ifElseStmtContext = dynamic_cast<FlyScriptParser::IfElseStmtContext *>(stmtContext)) {
                stmtContextParser->onVisitIfElseStmtContext(ifElseStmtContext);
            } else if (FlyScriptParser::WhileStmtContext *whileStmtContext = dynamic_cast<FlyScriptParser::WhileStmtContext *>(stmtContext)) {
                stmtContextParser->onVisitWhileStmtContext(whileStmtContext);
            } else if (FlyScriptParser::BreakStmtContext *breakStmtContext = dynamic_cast<FlyScriptParser::BreakStmtContext *>(stmtContext)) {
                stmtContextParser->onVisitBreakStmtContext(breakStmtContext);
            } else if (FlyScriptParser::ReturnStmtContext *returnStmtContext = dynamic_cast<FlyScriptParser::ReturnStmtContext *>(stmtContext)) {
                stmtContextParser->onVisitReturnStmtContext(returnStmtContext);
            }
        }
    }

};

#endif //FLYLANGUAGE_STMTCONTEXTPARSER_H
