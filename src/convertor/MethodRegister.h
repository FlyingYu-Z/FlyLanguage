//
// Created by flying on 2023/1/7.
//

#ifndef FLYLANGUAGE_METHODREGISTER_H
#define FLYLANGUAGE_METHODREGISTER_H


class Ast2IrConvertor;

class TypeInMethodRemember;

class MethodRegister {

protected:
    int usedRegister = 0;
    //variableName,register
    map<string_view, int> registerMap = map<string_view, int>();
    TypeInMethodRemember *typeInMethodRemember;
    vector<Instruction> instructions = vector<Instruction>();
    vector<Instruction> subInstructions = vector<Instruction>();
    bool subInstructionEnabled = false;

public:
    MethodRegister(Ast2IrConvertor *ast2IrConvertor);
    void addInstruction(Instruction instruction);
    vector<Instruction> getInstructions();
    vector<Instruction> getSubInstructions();
    void enableSubInstruction();
    void disableSubInstruction();
    int getSubtractedSize();
    void rememberRegister(string_view variableName,int registerA);
    int getRegister(string_view variableName);
    int newRegister();
    int newRegister(string_view variableName);
    int currentCodeAddress();
    ~MethodRegister();

};

#endif //FLYLANGUAGE_METHODREGISTER_H
