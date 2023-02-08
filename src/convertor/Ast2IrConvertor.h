//
// Created by flying on 2023/1/5.
//

#ifndef FLYLANGUAGE_AST2IRCONVERTOR_H
#define FLYLANGUAGE_AST2IRCONVERTOR_H

#include "antlr4-runtime.h"
#include "ValueType.h"
#include "TypeInClassRemember.h"
#include "TypeInMethodRemember.h"
#include "PlusSubTypeInference.h"
#include "IrMethod.h"
#include "MethodBlock.h"
#include "BlockState.h"
#include "Function2IrMethodConvertor.h"
#include "NonRegisterException.h"
#include "CompileException.h"
//#include "parser/StmtContextInstructionParser.h"

class StmtContextInstructionParser;

using namespace beingyi;
using namespace antlr4;
using namespace antlr4::tree;

class ExprResult {
private:
    vector<Instruction *> instructions = vector<Instruction *>();

public:
    int resultRegister = 0;

    ExprResult() {

    }

    int getInstructionCount() const {
        return instructions.size();
    }

    const vector<Instruction *> &getInstructions() const {
        return instructions;
    }

    int getResultRegister() const {
        return resultRegister;
    }

    void setResultRegister(int resultRegister) {
        ExprResult::resultRegister = resultRegister;
    }

    void addInstruction(Instruction *instruction) {
        ExprResult::instructions.push_back(instruction);
    }

    void commitInstruction(vector<Instruction *> &list) {
        for (Instruction *instruction: instructions) {
            list.push_back(instruction);
        }
    }

    void commitInstruction(ExprResult &exprResult) {
        for (Instruction *instruction: instructions) {
            exprResult.addInstruction(instruction);
        }
    }

    void commitInstruction(MethodBlock *methodBlock) {
        for (Instruction *instruction: instructions) {
            methodBlock->addInstruction(instruction);
        }
    }

    ~ExprResult() {
        instructions.clear();
    }

};


class Ast2IrConvertor {

protected:
    FlyScriptParser::FileContext *tree;

public:
    TypeInClassRemember *typeInClassRemember = new TypeInClassRemember();

    Ast2IrConvertor(FlyScriptParser::FileContext *fileContext);

    void parseBlock(FlyScriptParser::BlockContext *blockContext, MethodBlock *methodBlock);

    void parseStmt(vector<ParseTree *> rawStmtList, MethodBlock *methodBlock);

    ExprResult getExprResult(FlyScriptParser::ExprContext *exprContext, int type, MethodBlock *methodBlock);

    FileClass *generateFileClass();

    ~Ast2IrConvertor();

    static string typeContextToString(FlyScriptParser::TypeContext *typeContext);


};


#endif //FLYLANGUAGE_AST2IRCONVERTOR_H
