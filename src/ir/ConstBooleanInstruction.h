//
// Created by flying on 2023/1/9.
//

#ifndef FLYLANGUAGE_CONSTBOOLEANINSTRUCTION_H
#define FLYLANGUAGE_CONSTBOOLEANINSTRUCTION_H

#include "Instruction.h"

class ConstBooleanInstruction : public Instruction {

protected:
    int registerA;
    bool value;

public:
    ConstBooleanInstruction(int registerA, bool value) : registerA(registerA), value(value) {

    }

    virtual ~ConstBooleanInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    bool isValue() const {
        return value;
    }

    int getOpcode() override {
        return Opcode::ConstBoolean;
    }

};



#endif //FLYLANGUAGE_CONSTBOOLEANINSTRUCTION_H
