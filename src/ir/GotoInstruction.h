//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_GOTOINSTRUCTION_H
#define FLYLANGUAGE_GOTOINSTRUCTION_H

#include "Instruction.h"

class GotoInstruction : public Instruction {

protected:
    int address;

public:
    GotoInstruction(int address) : address(address) {

    }

    virtual ~GotoInstruction() {
    }

    int getAddress() const {
        return address;
    }

    void setAddress(int address) {
        GotoInstruction::address = address;
    }

    int getOpcode() override {
        return Opcode::Goto;
    }

};

#endif //FLYLANGUAGE_GOTOINSTRUCTION_H
