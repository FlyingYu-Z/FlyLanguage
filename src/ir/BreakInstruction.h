//
// Created by flying on 2023/2/8.
//

#ifndef FLYLANGUAGE_BREAKINSTRUCTION_H
#define FLYLANGUAGE_BREAKINSTRUCTION_H

#include "Instruction.h"

class BreakInstruction : public Instruction {

public:
    BreakInstruction() : Instruction(){

    }
    virtual ~BreakInstruction() {
    }

    int getOpcode() override {
        return Opcode::Break;
    }

};


#endif //FLYLANGUAGE_BREAKINSTRUCTION_H
