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
    map<int, bool> subInstructionSwitchMap = map<int, bool>();
    map<int, vector<Instruction *> *> subInstructionsMap = map<int, vector<Instruction *> *>();
    int subKey = 0;
public:
    typedef vector<Instruction *> InstructionList;
    TypeInMethodRemember *typeInMethodRemember;
    PlusSubTypeInference *plusSubTypeInference;


    MethodRegister(Ast2IrConvertor *ast2IrConvertor);

private:
    bool isSubInstructionEnabled();

public:
    void addInstruction(Instruction *instruction);

    void addInstruction(int index,Instruction *instruction);

    vector<Instruction *> getInstructions();

    vector<Instruction *> getSubInstructions();

    void enableSubInstruction();

    void disableSubInstruction();

    int getSubtractedSize();

    void clearSubInstructions();

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
