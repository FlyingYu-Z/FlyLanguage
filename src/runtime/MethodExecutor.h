//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_METHODEXECUTOR_H
#define FLYLANGUAGE_METHODEXECUTOR_H

#include "ValueType.h"
#include "IrMethod.h"
#include "NonRegisterException.h"
#include "RuntimeException.h"
#include "Value.h"
#include <any>
#include <map>

class ClassRuntime;

using namespace std;

class MethodExecutor {

protected:
    ClassRuntime *classRuntime;
    IrMethod *irMethod;
    vector<Instruction *> instructions;
    int execCodeAddress = 0;
    bool finished = false;
    map<int, Value> registerValueMap = map<int, Value>();
    vector<Value> paramValues = vector<Value>();
    Value *currentResultValue = nullptr;
    Value *returnResultValue = nullptr;

public:
    MethodExecutor(ClassRuntime *classRuntime, IrMethod *irMethod);

    void setParamValues(vector<Value> values);

    Value getRegisterValue(int registerA);

    void setRegisterValue(int registerA, Value value);

    void moveObjectResult(int registerA);

    void gotoAddress(int address);

    bool hasNextInstruction();

    Instruction *nextInstruction();

    void setCurrentResult(Value value);

    void returnResult(Value value);
    void returnVoid();

    Value *getReturnedResult();

    void execute();

    ~MethodExecutor();
};


#endif //FLYLANGUAGE_METHODEXECUTOR_H
