//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_CONSTPARAMINSTRUCTION_H
#define FLYLANGUAGE_CONSTPARAMINSTRUCTION_H

#include "Instruction.h"

class ConstParamInstruction : public Instruction {

protected:
    int registerA;
    int paramIndex;

public:
    ConstParamInstruction(int registerA, int paramIndex) : Instruction(),registerA(registerA), paramIndex(paramIndex) {

    }
    virtual ~ConstParamInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    int getParamIndex() const {
        return paramIndex;
    }

    int getOpcode() override {
        return Opcode::ConstParam;
    }

};


#endif //FLYLANGUAGE_CONSTPARAMINSTRUCTION_H
