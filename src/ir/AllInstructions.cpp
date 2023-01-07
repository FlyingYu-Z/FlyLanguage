//
// Created by flying on 2023/1/7.
//
#include "AllInstructions.h"

static string_view dump(Instruction *instruction) {
    int opcode = instruction->getOpcode();
    const char *opcodeName = Opcode::getName(opcode);
    std::string formatted="";
    switch (opcode) {
        case Opcode::Value::ConstInt:
            ConstIntInstruction *constIntInstruction = dynamic_cast<ConstIntInstruction*>(instruction);
            //formatted = fmt::sprintf("%s v%d,%d", opcodeName, constStringInstruction->getRegisterA(), constStringInstruction->getValue().data());
            break;
        case Opcode::Value::ConstString:
            ConstStringInstruction *constStringInstruction = dynamic_cast<ConstStringInstruction*>(instruction);
            //formatted = fmt::sprintf("%s v%d,\"%s\"", opcodeName, constStringInstruction->getRegisterA(), constStringInstruction->getValue().data());
            break;
        default:
            throw std::runtime_error("unknown opcode value");
            //break;
    }
    int length = formatted.length() + 1;
    char *tmp=new char[length];
    sprintf(tmp, "%s", formatted.c_str());
    tmp[length - 1] = '\0';
    string_view result(tmp);
    return result;
}