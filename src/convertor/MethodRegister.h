//
// Created by flying on 2023/1/7.
//

#ifndef FLYLANGUAGE_METHODREGISTER_H
#define FLYLANGUAGE_METHODREGISTER_H

#include "PlusSubTypeInference.h"

class Ast2IrConvertor;

class TypeInMethodRemember;

class PlusSubTypeInference;

class MethodRegister {

protected:
    int usedRegister = 1;
    //variableName,register
    map<string, int> registerMap = map<string, int>();
    vector<Instruction *> instructions = vector<Instruction *>();
    vector<Instruction *> subInstructions = vector<Instruction *>();
    bool subInstructionEnabled = false;

public:
    TypeInMethodRemember *typeInMethodRemember;
    PlusSubTypeInference *plusSubTypeInference;

    MethodRegister(Ast2IrConvertor *ast2IrConvertor);

    void addInstruction(Instruction *instruction);

    vector<Instruction *> getInstructions();

    vector<Instruction *> getSubInstructions();

    void enableSubInstruction();

    void disableSubInstruction();

    int getSubtractedSize();

    void rememberRegister(string variableName, int registerA);

    int getRegister(string variableName);

    int newRegister();

    int newRegister(string variableName);

    int currentCodeAddress();

    int getExprType(FlyScriptParser::ExprContext *exprContext);

    bool isFieldVariable(FlyScriptParser::IdentifierExprContext *identifierExprContext);

    bool isFieldVariable(string variableName);

    ~MethodRegister();

};

#endif //FLYLANGUAGE_METHODREGISTER_H
