//
// Created by flying on 2023/1/6.
//

#ifndef FLYLANGUAGE_INSTRUCTION_H
#define FLYLANGUAGE_INSTRUCTION_H

#include "Opcode.hpp"

class Instruction {

protected:
public:
    Instruction() {}

    virtual ~Instruction() {}

    virtual int getOpcode() { return Opcode::Nop; }

    virtual string_view toString() { return Opcode::getName(getOpcode());}

};

#endif //FLYLANGUAGE_INSTRUCTION_H
