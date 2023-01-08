//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_INVOKEINSTRUCTION_H
#define FLYLANGUAGE_INVOKEINSTRUCTION_H

#include "Instruction.h"

class InvokeInstruction : public Instruction {

protected:
    string_view methodName;
    vector<int> registerList;

public:
    InvokeInstruction(const string_view &methodName, const vector<int> &registerList) : methodName(methodName),
                                                                                        registerList(registerList) {

    }

    virtual ~InvokeInstruction() {

    }

    const string_view &getMethodName() const {
        return methodName;
    }

    const vector<int> &getRegisterList() const {
        return registerList;
    }

    int getOpcode() override {
        return Opcode::Invoke;
    }

};

#endif //FLYLANGUAGE_INVOKEINSTRUCTION_H
