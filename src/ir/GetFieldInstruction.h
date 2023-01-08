//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_GETFIELDINSTRUCTION_H
#define FLYLANGUAGE_GETFIELDINSTRUCTION_H

#include "Instruction.h"

class GetFieldInstruction : public Instruction {

protected:
    int registerA;
    string fieldName;

public:
    GetFieldInstruction(int registerA, const string &fieldName) : Instruction(),registerA(registerA), fieldName(fieldName) {

    }

    virtual ~GetFieldInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    const string &getFieldName() const {
        return fieldName;
    }

    int getOpcode() override {
        return Opcode::GetField;
    }

};

#endif //FLYLANGUAGE_GETFIELDINSTRUCTION_H
