//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_IFINSTRUCTION_H
#define FLYLANGUAGE_IFINSTRUCTION_H

#include "Instruction.h"

class IfInstruction : public Instruction {

protected:
    int registerA;
    int address;

public:
    IfInstruction(int registerA, int address) : Instruction(), registerA(registerA), address(address) {

    }

    virtual ~IfInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    void setRegisterA(int registerA) {
        IfInstruction::registerA = registerA;
    }

    int getAddress() const {
        return address;
    }

    void setAddress(int address) {
        IfInstruction::address = address;
    }

    int getOpcode() override {
        return Opcode::If;
    }

};


#endif //FLYLANGUAGE_IFINSTRUCTION_H
