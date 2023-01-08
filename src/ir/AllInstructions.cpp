//
// Created by flying on 2023/1/7.
//
#include "AllInstructions.h"

string_view dump(Instruction *instruction) {
    int opcode = instruction->getOpcode();
    const char *opcodeName = Opcode::getOpcodeName(opcode);
    std::string formatted="";
    switch (opcode) {
        case Opcode::ConstInt:{
            ConstIntInstruction *constIntInstruction = dynamic_cast<ConstIntInstruction*>(instruction);
            formatted = fmt::sprintf("%s v%d,%d", opcodeName, constIntInstruction->getRegisterA(), constIntInstruction->getValue());
            }
            break;
        case Opcode::ConstString:{
            ConstStringInstruction *constStringInstruction = dynamic_cast<ConstStringInstruction*>(instruction);
            formatted = fmt::sprintf("%s v%d,\"%s\"", opcodeName, constStringInstruction->getRegisterA(), constStringInstruction->getValue().data());
            }
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