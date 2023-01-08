//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_SETFIELDINSTRUCTION_H
#define FLYLANGUAGE_SETFIELDINSTRUCTION_H

#include "Instruction.h"

class SetFieldInstruction : public Instruction {

protected:
    int registerA;
    string fieldName;

public:
    SetFieldInstruction(int registerA, const string &fieldName) : Instruction(),registerA(registerA), fieldName(fieldName) {

    }

    virtual ~SetFieldInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    const string &getFieldName() const {
        return fieldName;
    }

    int getOpcode() override {
        return Opcode::SetField;
    }

};

#endif //FLYLANGUAGE_SETFIELDINSTRUCTION_H
