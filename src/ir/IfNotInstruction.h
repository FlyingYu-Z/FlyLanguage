//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_IFNOTINSTRUCTION_H
#define FLYLANGUAGE_IFNOTINSTRUCTION_H


#include "Instruction.h"

class IfNotInstruction : public Instruction {

protected:
    int registerA;
    int address;

public:
    IfNotInstruction(int registerA, int address) : Instruction(), registerA(registerA), address(address) {

    }

    virtual ~IfNotInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    int getAddress() const {
        return address;
    }

    int getOpcode() override {
        return Opcode::IfNot;
    }

};



#endif //FLYLANGUAGE_IFNOTINSTRUCTION_H
