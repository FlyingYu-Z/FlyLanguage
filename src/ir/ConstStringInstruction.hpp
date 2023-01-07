//
// Created by flying on 2023/1/6.
//

#ifndef FLYLANGUAGE_CONSTSTRINGINSTRUCTION_H
#define FLYLANGUAGE_CONSTSTRINGINSTRUCTION_H

#include "Instruction.hpp"
#include <fmt/printf.h>


class ConstStringInstruction : public Instruction {

protected:
    int registerA;
    string_view value;

public:
    ConstStringInstruction(int registerA, const string_view &value)
            : Instruction(), registerA(registerA), value(value) {

    }

    virtual ~ConstStringInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    const string_view &getValue() const {
        return value;
    }

    int getOpcode() override {
        return Opcode::ConstString;
    }

    string_view toString() override {
        const char *opcodeName = Opcode::getName(getOpcode());
        std::string formatted = fmt::sprintf("%s v%d,\"%s\"", opcodeName, registerA, value.data());
        int length = formatted.length() + 1;
        char *tmp=new char[length];
        sprintf(tmp, "%s", formatted.c_str());
        tmp[length - 1] = '\0';
        string_view result(tmp);
        return result;
    }

};


#endif //FLYLANGUAGE_CONSTSTRINGINSTRUCTION_H
