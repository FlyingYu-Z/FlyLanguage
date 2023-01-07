//
// Created by flying on 2023/1/6.
//

#ifndef FLYLANGUAGE_INSTRUCTION_H
#define FLYLANGUAGE_INSTRUCTION_H

#include <fmt/printf.h>
#include "StringPool.h"
#include "Opcode.hpp"

class Instruction {

protected:
public:
    Instruction() {}

    virtual ~Instruction() {}

    virtual int getOpcode() { return Opcode::Nop; }

    virtual string_view toString() { return Opcode::getName(getOpcode()); }

    static string_view sump(Instruction instruction) {
        int opcode = instruction.getOpcode();
        const char *opcodeName = Opcode::getName(opcode);
        std::string formatted;
        switch (opcode) {
            case Opcode::Value::ConstString:
                formatted = fmt::sprintf("%s v%d,\"%s\"", opcodeName, instruction.registerA, value.data());
                break;
            case Opcode::Value::ConstInt:

                break;
            default:
                throw std::runtime_error("unknown opcode value");
                break;
        }
        int length = formatted.length() + 1;
        char *tmp=new char[length];
        sprintf(tmp, "%s", formatted.c_str());
        tmp[length - 1] = '\0';
        string_view result(tmp);
        return result;
    }
};

#endif //FLYLANGUAGE_INSTRUCTION_H
