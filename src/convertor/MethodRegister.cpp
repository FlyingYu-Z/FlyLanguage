//
// Created by flying on 2023/1/7.
//

#include "Ast2IrConvertor.h"
#include "MethodRegister.h"


MethodRegister::MethodRegister(Ast2IrConvertor *ast2IrConvertor) {
    this->typeInMethodRemember = new TypeInMethodRemember(ast2IrConvertor->typeInClassRemember);
}

void MethodRegister::addInstruction(Instruction instruction) {
    if (subInstructionEnabled) {
        subInstructions.push_back(instruction);
    } else {
        instructions.push_back(instruction);
    }
}

vector<Instruction> MethodRegister::getInstructions() {
    return instructions;
}

vector<Instruction> MethodRegister::getSubInstructions() {
    return subInstructions;
}

void MethodRegister::enableSubInstruction() {
    subInstructionEnabled = true;
    subInstructions.clear();
}

void MethodRegister::disableSubInstruction() {
    subInstructionEnabled = false;
}

int MethodRegister::getSubtractedSize() {
    return subInstructions.size();
}

void MethodRegister::rememberRegister(string_view variableName, int registerA) {
    registerMap[variableName] = registerA;
}

int MethodRegister::getRegister(string_view variableName) {
    return registerMap[variableName];
}

int MethodRegister::newRegister() {
    return newRegister(NULL);
}

int MethodRegister::newRegister(string_view variableName) {
    int registerA = usedRegister++;
    if (variableName != NULL) {
        rememberRegister(variableName, registerA);
    }
    return registerA;
}

int MethodRegister::currentCodeAddress() {
    return instructions.size() - 1;
}

bool MethodRegister::isFieldVariable(FlyScriptParser::IdentifierExprContext *identifierExprContext) {
    string_view variableName = identifierExprContext->children[0]->getText();
    return isFieldVariable(variableName);
}

bool MethodRegister::isFieldVariable(string_view variableName) {
    int fieldType = typeInMethodRemember->typeInClassRemember->getFieldType(variableName);
    return fieldType != 0;
}

MethodRegister::~MethodRegister() {

}
