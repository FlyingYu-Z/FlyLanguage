//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_CONSTFLOATINSTRUCTION_H
#define FLYLANGUAGE_CONSTFLOATINSTRUCTION_H

#include "Instruction.h"

class ConstFloatInstruction : public Instruction {

protected:
    int registerA;
    float value;

public:
    ConstFloatInstruction(int registerA, int value) : Instruction(),registerA(registerA), value(value) {

    }
    virtual ~ConstFloatInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    float getValue() const {
        return value;
    }

    int getOpcode() override {
        return Opcode::ConstFloat;
    }

};



#endif //FLYLANGUAGE_CONSTFLOATINSTRUCTION_H
