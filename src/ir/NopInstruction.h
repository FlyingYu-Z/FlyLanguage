//
// Created by flying on 2023/1/10.
//

#ifndef FLYLANGUAGE_NOPINSTRUCTION_H
#define FLYLANGUAGE_NOPINSTRUCTION_H
#include "Instruction.h"

class NopInstruction : public Instruction {

public:
    NopInstruction() : Instruction(){

    }
    virtual ~NopInstruction() {
    }

    int getOpcode() override {
        return Opcode::Nop;
    }

};


#endif //FLYLANGUAGE_NOPINSTRUCTION_H
