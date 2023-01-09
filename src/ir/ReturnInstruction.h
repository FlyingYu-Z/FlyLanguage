//
// Created by flying on 2023/1/9.
//

#ifndef FLYLANGUAGE_RETURNINSTRUCTION_H
#define FLYLANGUAGE_RETURNINSTRUCTION_H

#include "Instruction.h"

class ReturnInstruction : public Instruction {

protected:
    int registerA;
    bool isVoid;

public:
    ReturnInstruction(int registerA, bool isVoid) : registerA(registerA), isVoid(isVoid) {

    }

    ReturnInstruction() : registerA(-1), isVoid(true) {

    }

    virtual ~ReturnInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    bool isVoidType() const {
        return isVoid;
    }

    int getOpcode() override {
        return Opcode::Return;
    }

};


#endif //FLYLANGUAGE_RETURNINSTRUCTION_H
