//
// Created by flying on 2023/1/7.
//

#include "Ast2IrConvertor.h"
#include "MethodRegister.h"


MethodRegister::MethodRegister(Ast2IrConvertor *ast2IrConvertor) {
    this->typeInMethodRemember = new TypeInMethodRemember(ast2IrConvertor->typeInClassRemember);
    this->plusSubTypeInference = new PlusSubTypeInference(this);
}

void MethodRegister::addInstruction(Instruction *instruction) {
    if (subInstructionEnabled) {
        subInstructions.push_back(instruction);
    } else {
        instructions.push_back(instruction);
    }
}

vector<Instruction *> MethodRegister::getInstructions() {
    return instructions;
}

vector<Instruction *> MethodRegister::getSubInstructions() {
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

void MethodRegister::rememberRegister(string variableName, int registerA) {
    registerMap[variableName] = registerA;
}

int MethodRegister::getRegister(string variableName) {
    return registerMap[variableName];
}

int MethodRegister::newRegister() {
    return newRegister("");
}

int MethodRegister::newRegister(string variableName) {
    int registerA = usedRegister++;
    if (!variableName.empty()) {
        rememberRegister(variableName, registerA);
    }
    return registerA;
}

int MethodRegister::currentCodeAddress() {
    return instructions.size() - 1;
}


int MethodRegister::getExprType(FlyScriptParser::ExprContext *exprContext) {
    if (FlyScriptParser::IntExprContext *intExprContext = dynamic_cast<FlyScriptParser::IntExprContext *>(exprContext)) {
        return ValueType::T_int;
    } else if (FlyScriptParser::StringExprContext *stringExprContext = dynamic_cast<FlyScriptParser::StringExprContext *>(exprContext)) {
        return ValueType::T_string;
    } else if (FlyScriptParser::IdentifierExprContext *identifierExprContext = dynamic_cast<FlyScriptParser::IdentifierExprContext *>(exprContext)) {
        string variableName = identifierExprContext->children[0]->getText();
        int variableType = 0;
        if (isFieldVariable(identifierExprContext)) {
            variableType = typeInMethodRemember->typeInClassRemember->getFieldType(variableName);
        } else {
            variableType = typeInMethodRemember->getVariableType(variableName);
        }
        if (variableType == 0) {
            throw CompileException(fmt::sprintf("cannot get the real variable type:%s", variableName));
        }
        return variableType;
    } else if (FlyScriptParser::InvokeExprContext *invokeExprContext = dynamic_cast<FlyScriptParser::InvokeExprContext *>(exprContext)) {

    } else if (FlyScriptParser::PlusSubExprContext *plusSubExprContext = dynamic_cast<FlyScriptParser::PlusSubExprContext *>(exprContext)) {
        return plusSubTypeInference->getRealExprType(plusSubExprContext);
    }
    throw CompileException("unknown expr");
}

bool MethodRegister::isFieldVariable(FlyScriptParser::IdentifierExprContext *identifierExprContext) {
    string variableName = identifierExprContext->children[0]->getText();
    return isFieldVariable(variableName);
}

bool MethodRegister::isFieldVariable(string variableName) {
    int fieldType = typeInMethodRemember->typeInClassRemember->getFieldType(variableName);
    return fieldType != 0;
}

MethodRegister::~MethodRegister() {

}
