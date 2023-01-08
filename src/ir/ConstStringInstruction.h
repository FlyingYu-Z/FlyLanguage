//
// Created by flying on 2023/1/6.
//

#ifndef FLYLANGUAGE_CONSTSTRINGINSTRUCTION_H
#define FLYLANGUAGE_CONSTSTRINGINSTRUCTION_H

#include "Instruction.h"
#include <fmt/printf.h>


class ConstStringInstruction : public Instruction {

protected:
    int registerA;
    string value;

public:
    ConstStringInstruction(int registerA, const string &value)
            : Instruction(), registerA(registerA), value(value) {

    }

    virtual ~ConstStringInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    const string &getValue() const {
        return value;
    }

    int getOpcode() override {
        return Opcode::ConstString;
    }

};


#endif //FLYLANGUAGE_CONSTSTRINGINSTRUCTION_H
