//
// Created by flying on 2023/1/7.
//

#ifndef FLYLANGUAGE_METHODBLOCK_H
#define FLYLANGUAGE_METHODBLOCK_H

#include "AllInstructions.h"

class Ast2IrConvertor;

class TypeInClassRemember;

class TypeInMethodRemember;

class PlusSubTypeInference;

class BlockState;

class MethodBlock {

protected:
    TypeInClassRemember *typeInClassRemember = nullptr;
    vector<Instruction *> instructions = vector<Instruction *>();
    bool isChild = false;
    int breakCodeAddress = -1;
    bool isWhileBlock = false;
public:
    //MethodBlock *topMethodBlock = nullptr;
    MethodBlock *parentMethodBlock = nullptr;
    typedef vector<Instruction *> InstructionList;
    BlockState *state = nullptr;


    MethodBlock(TypeInClassRemember *typeInClassRemember);

private:
    bool isSubInstructionEnabled();

public:
    MethodBlock *newChildBlock();

    int addInstruction(Instruction *instruction);

    void replaceInstruction(int index, Instruction *instruction);

    vector<Instruction *> getInstructions();

    int previousCodeAddress();

    int currentCodeAddress();

    int currentCodeAddressForChild();

    int nextCodeAddress();

    int nextCodeAddressForChild();

    int getBreakCodeAddress() const;

    void setIsWhileBlock(bool isWhileBlock);

    MethodBlock *findWhileBlock();

    void setBreakCodeAddress(int breakCodeAddress);

    ~MethodBlock();

};

#endif //FLYLANGUAGE_METHODBLOCK_H
