//
// Created by flying on 2023/1/8.
//

#include "MethodExecutor.h"
#include "ClassRuntime.h"
#include "SystemMethod.h"
#include "BoolValueCalc.h"
#include "bits.h"
#include "IntValueCompare.h"

MethodExecutor::MethodExecutor(ClassRuntime *classRuntime, IrMethod *irMethod) : classRuntime(classRuntime),
                                                                                 irMethod(irMethod) {
    this->instructions = irMethod->getInstructions();
}

void MethodExecutor::setParamValues(vector<any> values) {
    for (any v: values) {
        this->paramValues.push_back(v);
    }
}

any MethodExecutor::getRegisterValue(int registerA) {
    return registerValueMap[registerA];
}

void MethodExecutor::setRegisterValue(int registerA, any value) {
    registerValueMap[registerA] = value;
}

void MethodExecutor::moveObjectResult(int registerA) {
    setRegisterValue(registerA, currentResult);
    currentResult = nullptr;
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

void MethodExecutor::returnVoid() {
    finished = true;
    returnResult = nullptr;
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
                registerValueMap[constIntInstruction->getRegisterA()] = constIntInstruction->getValue();
                break;
            }
            case Opcode::ConstString: {
                ConstStringInstruction *constStringInstruction = dynamic_cast<ConstStringInstruction *>(instruction);
                registerValueMap[constStringInstruction->getRegisterA()] = constStringInstruction->getValue();
                break;
            }
            case Opcode::ConstFloat: {
                ConstFloatInstruction *constFloatInstruction = dynamic_cast<ConstFloatInstruction *>(instruction);
                registerValueMap[constFloatInstruction->getRegisterA()] = constFloatInstruction->getValue();
                break;
            }
            case Opcode::ConstParam: {
                ConstParamInstruction *constParamInstruction = dynamic_cast<ConstParamInstruction *>(instruction);
                registerValueMap[constParamInstruction->getRegisterA()] = paramValues[constParamInstruction->getParamIndex()];
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
                vector<any> argList = vector<any>();
                vector<int> regList = invokeInstruction->getRegisterList();
                for (int i = 0; i < regList.size(); i++) {
                    argList.push_back(getRegisterValue(regList[i]));
                }
                break;
            }
            case Opcode::Plus: {
                PlusInstruction *plusInstruction = dynamic_cast<PlusInstruction *>(instruction);
                break;
            }
            case Opcode::Sub: {
                SubInstruction *subInstruction = dynamic_cast<SubInstruction *>(instruction);
                break;
            }
            case Opcode::Bool: {
                BoolInstruction *boolInstruction = dynamic_cast<BoolInstruction *>(instruction);
                any valueA = getRegisterValue(boolInstruction->getRegisterA());
                int symbol=boolInstruction->getSymbol();
                any valueB = getRegisterValue(boolInstruction->getRegisterB());

                int type1 = ValueCalc::ctype2vtype(valueA.type());
                int type2 = ValueCalc::ctype2vtype(valueB.type());

                int highestType = ValueCalc::getHighestType(type1, type2);
                switch (highestType) {
                    case ValueType::T_int:{
                        IntValueCompare intValueCompare=IntValueCompare(any_cast<int>(valueA),symbol, any_cast<int>(valueB));
                        currentResult=intValueCompare.compare();
                        break;
                    }
                }
                break;
            }
            case Opcode::If: {
                IfInstruction *ifInstruction = dynamic_cast<IfInstruction *>(instruction);
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
            default:
                throw RuntimeException("unsupported instruction opcode:" + opcode);
        }
    }
    printf("finished");
}

MethodExecutor::~MethodExecutor() {

}



