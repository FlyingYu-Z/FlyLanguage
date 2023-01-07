//
// Created by flying on 2023/1/6.
//

#ifndef FLYLANGUAGE_CONSTINTINSTRUCTION_H
#define FLYLANGUAGE_CONSTINTINSTRUCTION_H

#include "Instruction.h"

class ConstIntInstruction : public Instruction {

protected:
    int registerA;
    int value;

public:
    ConstIntInstruction(int registerA, int value) : Instruction(),registerA(registerA), value(value) {

    }
    virtual ~ConstIntInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    int getValue() const {
        return value;
    }

    int getOpcode() override {
        return Opcode::ConstInt;
    }

};


#endif //FLYLANGUAGE_CONSTINTINSTRUCTION_H
