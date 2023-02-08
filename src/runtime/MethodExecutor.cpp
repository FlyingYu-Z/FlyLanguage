//
// Created by flying on 2023/1/8.
//

#include "MethodExecutor.h"
#include "ClassRuntime.h"
#include "SystemMethod.h"
#include "BoolValueCalc.h"
#include "bits.h"
#include "AllValueComprator.h"

MethodExecutor::MethodExecutor(ClassRuntime *classRuntime, IrMethod *irMethod) : classRuntime(classRuntime),
                                                                                 irMethod(irMethod) {
    this->instructions = irMethod->getInstructions();
}

void MethodExecutor::setParamValues(vector<Value> values) {
    for (Value v: values) {
        this->paramValues.push_back(v);
    }
}

Value MethodExecutor::getRegisterValue(int registerA) {
    return registerValueMap.at(registerA);
}

void MethodExecutor::setRegisterValue(int registerA, Value value) {
    auto iter = registerValueMap.find(registerA);
    if (iter != registerValueMap.end()) {
        registerValueMap.erase(iter);//delete if exists
    }
    registerValueMap.insert(map<int, Value>::value_type(registerA, value));
}

void MethodExecutor::moveObjectResult(int registerA) {
    if(!currentResultValue){
        throw RuntimeException("cannot exec moveObjectResult,because the value is null");
    }
    setRegisterValue(registerA, Value(currentResultValue->getType(), currentResultValue->getValue()));
    delete currentResultValue;
    currentResultValue = nullptr;
}

void MethodExecutor::gotoAddress(int address) {
    execCodeAddress = address;
}

bool MethodExecutor::hasNextInstruction() {
    if (finished) {
        return false;
    }
    return execCodeAddress < instructions.size();
}

Instruction *MethodExecutor::nextInstruction() {
    return instructions[execCodeAddress++];
}

void MethodExecutor::setCurrentResult(Value value) {
    currentResultValue = new Value(value.getType(), value.getValue());
}

void MethodExecutor::returnResult(Value value) {
    finished = true;
    returnResultValue = new Value(value.getType(), value.getValue());
}

void MethodExecutor::returnVoid() {
    finished = true;
    delete currentResultValue;
    returnResultValue = nullptr;
}

Value *MethodExecutor::getReturnedResult() {
    return returnResultValue;
    //return Value(returnResultValue->getType(), returnResultValue->getValue());
}

void MethodExecutor::execute() {
    while (!finished) {
        if (!hasNextInstruction()) {
            finished = true;
            break;
        }
        Instruction *instruction = nextInstruction();
        int opcode = instruction->getOpcode();
        switch (opcode) {
            case Opcode::Nop: {
                break;
            }
            case Opcode::ConstInt: {
                ConstIntInstruction *constIntInstruction = dynamic_cast<ConstIntInstruction *>(instruction);
                setRegisterValue(constIntInstruction->getRegisterA(),
                                 Value(ValueType::T_int, constIntInstruction->getValue()));
                break;
            }
            case Opcode::ConstString: {
                ConstStringInstruction *constStringInstruction = dynamic_cast<ConstStringInstruction *>(instruction);
                setRegisterValue(constStringInstruction->getRegisterA(),
                                 Value(ValueType::T_string, constStringInstruction->getValue()));
                break;
            }
            case Opcode::ConstFloat: {
                ConstFloatInstruction *constFloatInstruction = dynamic_cast<ConstFloatInstruction *>(instruction);
                setRegisterValue(constFloatInstruction->getRegisterA(),
                                 Value(ValueType::T_float, constFloatInstruction->getValue()));
                break;
            }
            case Opcode::ConstBoolean: {
                ConstBooleanInstruction *constBooleanInstruction = dynamic_cast<ConstBooleanInstruction *>(instruction);
                setRegisterValue(constBooleanInstruction->getRegisterA(),
                                 Value(ValueType::T_boolean, constBooleanInstruction->isValue()));
                break;
            }
            case Opcode::ConstParam: {
                ConstParamInstruction *constParamInstruction = dynamic_cast<ConstParamInstruction *>(instruction);
                Value paramValue = paramValues[constParamInstruction->getParamIndex()];
                setRegisterValue(constParamInstruction->getRegisterA(),
                                 Value(paramValue.getType(), paramValue.getValue()));
                break;
            }
            case Opcode::MoveResultObject: {
                MoveResultObjectInstruction *moveResultObjectInstruction = dynamic_cast<MoveResultObjectInstruction *>(instruction);
                moveObjectResult(moveResultObjectInstruction->getRegisterA());
                break;
            }
            case Opcode::Move: {
                MoveInstruction *moveInstruction = dynamic_cast<MoveInstruction *>(instruction);
                setRegisterValue(moveInstruction->getRegisterA(), getRegisterValue(moveInstruction->getRegisterB()));
                break;
            }
            case Opcode::Invoke: {
                InvokeInstruction *invokeInstruction = dynamic_cast<InvokeInstruction *>(instruction);
                string methodName = invokeInstruction->getMethodName();
                vector<int> regList = invokeInstruction->getRegisterList();
                if (SystemMethod::isSystemMethod(methodName)) {
                    vector<any> argList = vector<any>();
                    for (int i = 0; i < regList.size(); i++) {
                        argList.push_back(getRegisterValue(regList[i]).getValue());
                    }
                    SystemMethod::invokeMethod(methodName, argList);
                } else {
                    vector<Value> argList = vector<Value>();
                    for (int i = 0; i < regList.size(); i++) {
                        argList.push_back(getRegisterValue(regList[i]));
                    }
                    MethodExecutor methodExecutor = classRuntime->getMethodExecutor(methodName);
                    methodExecutor.setParamValues(argList);
                    methodExecutor.execute();
                    Value *returnedResult = methodExecutor.getReturnedResult();
                    if (returnedResult) {
                        setCurrentResult(*returnedResult);
                        delete returnedResult;
                    }
                }
                break;
            }
            case Opcode::Plus: {
                PlusInstruction *plusInstruction = dynamic_cast<PlusInstruction *>(instruction);
                Value valueA = getRegisterValue(plusInstruction->getRegisterA());
                Value valueB = getRegisterValue(plusInstruction->getRegisterB());
                int type1 = valueA.getType();
                int type2 = valueB.getType();
                int highestType = ValueCalc::getHighestTypeForPlusInstruction(type1, type2);
                switch (highestType) {
                    case ValueType::T_int: {
                        int castValue1 = any_cast<int>(valueA.getValue());
                        int castValue2 = any_cast<int>(valueB.getValue());
                        int plusValue = castValue1 + castValue2;
                        setCurrentResult(Value(ValueType::T_int, plusValue));
                        break;
                    }
                    case ValueType::T_float: {
                        float castValue1 = any_cast<float>(valueA.getValue());
                        float castValue2 = any_cast<float>(valueB.getValue());
                        float plusValue = castValue1 + castValue2;
                        setCurrentResult(Value(ValueType::T_float, plusValue));
                        break;
                    }
                    case ValueType::T_string: {
                        string castValue1 = ValueCalc::valueToString(type1, valueA.getValue());
                        string castValue2 = ValueCalc::valueToString(type2, valueB.getValue());
                        string plusValue = castValue1 + castValue2;
                        setCurrentResult(Value(ValueType::T_string, plusValue));
                        break;
                    }
                }
                break;
            }
            case Opcode::Sub: {
                SubInstruction *subInstruction = dynamic_cast<SubInstruction *>(instruction);
                Value valueA = getRegisterValue(subInstruction->getRegisterA());
                Value valueB = getRegisterValue(subInstruction->getRegisterB());
                int type1 = valueA.getType();
                int type2 = valueB.getType();
                int highestType = ValueCalc::getHighestTypeForPlusInstruction(type1, type2);
                switch (highestType) {
                    case ValueType::T_int: {
                        int castValue1 = any_cast<int>(valueA.getValue());
                        int castValue2 = any_cast<int>(valueB.getValue());
                        int plusValue = castValue1 - castValue2;
                        setCurrentResult(Value(ValueType::T_int, plusValue));
                        break;
                    }
                    case ValueType::T_float: {
                        float castValue1 = any_cast<float>(valueA.getValue());
                        float castValue2 = any_cast<float>(valueB.getValue());
                        float plusValue = castValue1 - castValue2;
                        setCurrentResult(Value(ValueType::T_float, plusValue));
                        break;
                    }
                }
                break;
            }
            case Opcode::Bool: {
                BoolInstruction *boolInstruction = dynamic_cast<BoolInstruction *>(instruction);
                Value valueA = getRegisterValue(boolInstruction->getRegisterA());
                int symbol = boolInstruction->getSymbol();
                Value valueB = getRegisterValue(boolInstruction->getRegisterB());
                int type1 = valueA.getType();
                int type2 = valueB.getType();
                int highestType = ValueCalc::getHighestTypeForBoolInstruction(type1, type2);
                switch (highestType) {
                    case ValueType::T_int: {
                        int castValue1 = any_cast<int>(valueA.getValue());
                        int castValue2 = any_cast<int>(valueB.getValue());
                        IntValueComparator intValueCompare = IntValueComparator(castValue1, symbol, castValue2);
                        setCurrentResult(Value(ValueType::T_boolean, intValueCompare.compare()));
                        break;
                    }
                    case ValueType::T_float: {
                        float castValue1 = any_cast<float>(valueA.getValue());
                        float castValue2 = any_cast<float>(valueB.getValue());
                        FloatValueComparator floatValueComparator = FloatValueComparator(castValue1, symbol, castValue2);
                        setCurrentResult(Value(ValueType::T_boolean, floatValueComparator.compare()));
                        break;
                    }
                }
                break;
            }
            case Opcode::If: {
                IfInstruction *ifInstruction = dynamic_cast<IfInstruction *>(instruction);
                Value value = getRegisterValue(ifInstruction->getRegisterA());
                bool castValue = any_cast<bool>(value.getValue());
                if (castValue) {
                    gotoAddress(ifInstruction->getAddress());
                }
                break;
            }
            case Opcode::IfNot: {
                IfNotInstruction *ifNotInstruction = dynamic_cast<IfNotInstruction *>(instruction);
                break;
            }
            case Opcode::Goto: {
                GotoInstruction *gotoInstruction = dynamic_cast<GotoInstruction *>(instruction);
                gotoAddress(gotoInstruction->getAddress());
                break;
            }
            case Opcode::SetField: {
                SetFieldInstruction *setFieldInstruction = dynamic_cast<SetFieldInstruction *>(instruction);
                classRuntime->setFieldValue(setFieldInstruction->getFieldName(),
                                            getRegisterValue(setFieldInstruction->getRegisterA()));
                break;
            }
            case Opcode::GetField: {
                GetFieldInstruction *getFieldInstruction = dynamic_cast<GetFieldInstruction *>(instruction);
                setRegisterValue(getFieldInstruction->getRegisterA(),
                                 classRuntime->getFieldValue(getFieldInstruction->getFieldName()));
                break;
            }
            case Opcode::Return: {
                ReturnInstruction *returnInstruction = dynamic_cast<ReturnInstruction *>(instruction);
                if (returnInstruction->isVoidType()) {
                    returnVoid();
                } else {
                    returnResult(getRegisterValue(returnInstruction->getRegisterA()));
                }
                break;
            }
            default:
                throw RuntimeException("unsupported instruction opcode:" + opcode);
        }
    }
    if (irMethod->getReturnType() != ValueType::T_void) {
        if (!returnResultValue) {
            throw RuntimeException(fmt::sprintf("non-void method must return an value:%s",irMethod->getName().data()));
        }
    }
}

MethodExecutor::~MethodExecutor() {

}



