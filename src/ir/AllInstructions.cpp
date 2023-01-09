//
// Created by flying on 2023/1/7.
//
#include "AllInstructions.h"

string dump(Instruction *instruction) {
    int opcode = instruction->getOpcode();
    const char *opcodeName = Opcode::getOpcodeName(opcode);
    std::string formatted = "";
    switch (opcode) {
        case Opcode::Nop: {
            formatted = fmt::sprintf("%s", opcodeName);
            break;
        }
        case Opcode::ConstInt: {
            ConstIntInstruction *constIntInstruction = dynamic_cast<ConstIntInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,%d", opcodeName, constIntInstruction->getRegisterA(),
                                     constIntInstruction->getValue());
            break;
        }
        case Opcode::ConstString: {
            ConstStringInstruction *constStringInstruction = dynamic_cast<ConstStringInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,\"%s\"", opcodeName, constStringInstruction->getRegisterA(),
                                     constStringInstruction->getValue().data());
            break;
        }
        case Opcode::ConstFloat: {
            ConstFloatInstruction *constFloatInstruction = dynamic_cast<ConstFloatInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,%s", opcodeName, constFloatInstruction->getRegisterA(),
                                     std::to_string(constFloatInstruction->getValue()));
            break;
        }
        case Opcode::ConstParam: {
            ConstParamInstruction *constParamInstruction = dynamic_cast<ConstParamInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,%d", opcodeName, constParamInstruction->getRegisterA(),
                                     constParamInstruction->getParamIndex());
            break;
        }
        case Opcode::MoveResultObject: {
            MoveResultObjectInstruction *moveResultObjectInstruction = dynamic_cast<MoveResultObjectInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d", opcodeName, moveResultObjectInstruction->getRegisterA());
            break;
        }
        case Opcode::Move: {
            MoveInstruction *moveInstruction = dynamic_cast<MoveInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,v%d", opcodeName, moveInstruction->getRegisterA(),
                                     moveInstruction->getRegisterB());
            break;
        }
        case Opcode::Invoke: {
            InvokeInstruction *invokeInstruction = dynamic_cast<InvokeInstruction *>(instruction);
            string params = "";
            for (int reg: invokeInstruction->getRegisterList()) {
                params = params + std::to_string(reg) + ",";
            }
            params.erase(params.end() - 1);
            formatted = fmt::sprintf("%s %s(%s)", opcodeName, invokeInstruction->getMethodName().data(), params.data());
            break;
        }
        case Opcode::Plus: {
            PlusInstruction *plusInstruction = dynamic_cast<PlusInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,v%d", opcodeName, plusInstruction->getRegisterA(),
                                     plusInstruction->getRegisterB());
            break;
        }
        case Opcode::Sub: {
            SubInstruction *subInstruction = dynamic_cast<SubInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,v%d", opcodeName, subInstruction->getRegisterA(),
                                     subInstruction->getRegisterB());
            break;
        }
        case Opcode::Bool: {
            BoolInstruction *boolInstruction = dynamic_cast<BoolInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d %s v%d", opcodeName, boolInstruction->getRegisterA(),
                                     BoolInstruction::getSymbolName(boolInstruction->getSymbol()),
                                     boolInstruction->getRegisterB());
            break;
        }
        case Opcode::If: {
            IfInstruction *ifInstruction = dynamic_cast<IfInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,%d", opcodeName, ifInstruction->getRegisterA(),
                                     ifInstruction->getAddress());
            break;
        }
        case Opcode::IfNot: {
            IfNotInstruction *ifNotInstruction = dynamic_cast<IfNotInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,%d", opcodeName, ifNotInstruction->getRegisterA(),
                                     ifNotInstruction->getAddress());
            break;
        }
        case Opcode::Goto: {
            GotoInstruction *gotoInstruction = dynamic_cast<GotoInstruction *>(instruction);
            formatted = fmt::sprintf("%s %d,%d", gotoInstruction->getAddress());
            break;
        }
        case Opcode::SetField: {
            SetFieldInstruction *setFieldInstruction = dynamic_cast<SetFieldInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,%s", setFieldInstruction->getRegisterA(),setFieldInstruction->getFieldName().data());
            break;
        }
        case Opcode::GetField: {
            GetFieldInstruction *getFieldInstruction = dynamic_cast<GetFieldInstruction *>(instruction);
            formatted = fmt::sprintf("%s v%d,%s", getFieldInstruction->getRegisterA(),getFieldInstruction->getFieldName().data());
            break;
        }
        default:
            throw std::runtime_error("unknown opcode value");
            //break;
    }
    int length = formatted.length() + 1;
    char *tmp = new char[length];
    sprintf(tmp, "%s", formatted.c_str());
    tmp[length - 1] = '\0';
    string result(tmp);
    return result;
}