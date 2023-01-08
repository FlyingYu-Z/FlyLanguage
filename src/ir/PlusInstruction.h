//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_PLUSINSTRUCTION_H
#define FLYLANGUAGE_PLUSINSTRUCTION_H


#include "Instruction.h"

class PlusInstruction : public Instruction {

protected:
    int registerA;
    int registerB;

public:
    PlusInstruction(int registerA, int registerB) : Instruction(), registerA(registerA), registerB(registerB) {

    }

    virtual ~PlusInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    int getRegisterB() const {
        return registerB;
    }

    int getOpcode() override {
        return Opcode::Plus;
    }

};


#endif //FLYLANGUAGE_PLUSINSTRUCTION_H
