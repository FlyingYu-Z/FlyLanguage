//
// Created by flying on 2023/1/7.
//

#ifndef FLYLANGUAGE_METHODBLOCK_H
#define FLYLANGUAGE_METHODBLOCK_H

#include "PlusSubTypeInference.h"

class Ast2IrConvertor;

class TypeInMethodRemember;

class PlusSubTypeInference;

class MethodBlock {

protected:
    Ast2IrConvertor *ast2IrConvertor = nullptr;
    int usedRegister = 1;
    //variableName,register
    map<string, int> registerMap = map<string, int>();
    vector<Instruction *> instructions = vector<Instruction *>();
    vector<int> preparedPosList = vector<int>();
    bool isChild = false;
    int breakCodeAddress = -1;
    bool isWhileBlock = false;
public:
    MethodBlock *topMethodBlock = nullptr;
    MethodBlock *parentMethodBlock = nullptr;
    typedef vector<Instruction *> InstructionList;
    TypeInMethodRemember *typeInMethodRemember;
    PlusSubTypeInference *plusSubTypeInference;


    MethodBlock(Ast2IrConvertor *ast2IrConvertor);

private:
    bool isSubInstructionEnabled();

public:
    MethodBlock *newChildBlock();

    int addInstruction(Instruction *instruction);

    void prepareInstruction(int count);

    void patchPreparedInstruction(Instruction *instruction);

    void patchPreparedInstructionForIndex(int index, Instruction *instruction);

    void addInstruction(int index, Instruction *instruction);

    void replaceInstruction(int index, Instruction *instruction);

    vector<Instruction *> getInstructions();

    void rememberRegister(string variableName, int registerA);

    int getRegister(string variableName);

    int newRegister();

    int newRegister(string variableName);

    int previousCodeAddress();

    int currentCodeAddress();

    int nextCodeAddress();

    int getExprType(FlyScriptParser::ExprContext *exprContext);

    bool isFieldVariable(FlyScriptParser::IdentifierExprContext *identifierExprContext);

    bool isFieldVariable(string variableName);

    int getBreakCodeAddress() const;

    void setIsWhileBlock(bool isWhileBlock);

    MethodBlock *findWhileBlock();

    void setBreakCodeAddress(int breakCodeAddress);

    ~MethodBlock();

};

#endif //FLYLANGUAGE_METHODBLOCK_H
