//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_MOVEINSTRUCTION_H
#define FLYLANGUAGE_MOVEINSTRUCTION_H

#include "Instruction.h"

class MoveInstruction : public Instruction {

protected:
    int registerA;
    int registerB;

public:
    MoveInstruction(int registerA, int registerB) : Instruction(), registerA(registerA), registerB(registerB) {

    }

    virtual ~MoveInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    int getRegisterB() const {
        return registerB;
    }

    int getOpcode() override {
        return Opcode::Move;
    }

};


#endif //FLYLANGUAGE_MOVEINSTRUCTION_H
