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
    vector<int> preparedPosList = vector<int>();
    bool isChild = false;
    int continueCodeAddress = 0;//useful only isChild=true
public:
    MethodRegister *parentMethodRegister;
    typedef vector<Instruction *> InstructionList;
    TypeInMethodRemember *typeInMethodRemember;
    PlusSubTypeInference *plusSubTypeInference;


    MethodRegister(Ast2IrConvertor *ast2IrConvertor);

    MethodRegister(MethodRegister *methodRegister);

private:
    bool isSubInstructionEnabled();

public:
    int addInstruction(Instruction *instruction);

    void prepareInstruction(int count);

    int prepareInstruction();

    void patchPreparedInstruction(Instruction *instruction);

    void patchPreparedInstructionForIndex(int index, Instruction *instruction);

    void addInstruction(int index, Instruction *instruction);

    void replaceInstruction(int index, Instruction *instruction);

    vector<Instruction *> getInstructions();

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
