//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_METHODEXECUTOR_H
#define FLYLANGUAGE_METHODEXECUTOR_H

#include "ValueType.h"
#include "IrMethod.h"
#include "NonRegisterException.h"
#include "RuntimeException.h"
#include <any>

class ClassRuntime;

using namespace std;

class MethodExecutor {

protected:
    ClassRuntime *classRuntime;
    IrMethod *irMethod;
    vector<Instruction *> instructions;
    int execCodeAddress = 0;
    bool finished = false;
    map<int, any> registerValueMap = map<int, any>();
    vector<any> paramValues=vector<any>();
    any currentResult = nullptr;
    any returnResult = nullptr;

public:
    MethodExecutor(ClassRuntime *classRuntime, IrMethod *irMethod);

    void setParamValues(vector<any> values);

    any getRegisterValue(int registerA);

    void setRegisterValue(int registerA, any value);

    void moveObjectResult(int registerA);

    void gotoAddress(int address);

    bool hasNextInstruction();

    Instruction *nextInstruction();

    void returnVoid();

    void execute();

    ~MethodExecutor();
};


#endif //FLYLANGUAGE_METHODEXECUTOR_H
