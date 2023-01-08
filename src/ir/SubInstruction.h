//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_SUBINSTRUCTION_H
#define FLYLANGUAGE_SUBINSTRUCTION_H

#include "Instruction.h"

class SubInstruction : public Instruction {

protected:
    int registerA;
    int registerB;

public:
    SubInstruction(int registerA, int registerB) : Instruction(), registerA(registerA), registerB(registerB) {

    }

    virtual ~SubInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    int getRegisterB() const {
        return registerB;
    }

    int getOpcode() override {
        return Opcode::Sub;
    }

};


#endif //FLYLANGUAGE_SUBINSTRUCTION_H
