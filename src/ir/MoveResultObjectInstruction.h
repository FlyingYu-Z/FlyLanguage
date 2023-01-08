//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_MOVERESULTOBJECTINSTRUCTION_H
#define FLYLANGUAGE_MOVERESULTOBJECTINSTRUCTION_H
#include "Instruction.h"

class MoveResultObjectInstruction : public Instruction {

protected:
    int registerA;

public:
    MoveResultObjectInstruction(int registerA) : Instruction(),registerA(registerA) {

    }
    virtual ~MoveResultObjectInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    int getOpcode() override {
        return Opcode::MoveResultObject;
    }

};

#endif //FLYLANGUAGE_MOVERESULTOBJECTINSTRUCTION_H
