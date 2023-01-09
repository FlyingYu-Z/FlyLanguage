//
// Created by flying on 2023/1/7.
//

#include "Ast2IrConvertor.h"
#include "MethodRegister.h"


MethodRegister::MethodRegister(Ast2IrConvertor *ast2IrConvertor) {
    this->typeInMethodRemember = new TypeInMethodRemember(ast2IrConvertor->typeInClassRemember);
    this->plusSubTypeInference = new PlusSubTypeInference(this);
}

bool MethodRegister::isSubInstructionEnabled(){
    return subInstructionSwitchMap[subKey];
}

void MethodRegister::addInstruction(Instruction *instruction) {
    if (isSubInstructionEnabled()) {
        vector<Instruction *> *subInstructions=subInstructionsMap[subKey];
        subInstructions->push_back(instruction);
    } else {
        instructions.push_back(instruction);
    }
}

void MethodRegister::addInstruction(int index,Instruction *instruction){
    if (isSubInstructionEnabled()) {
        vector<Instruction *> *subInstructions=subInstructionsMap[subKey];
        subInstructions->insert(subInstructions->begin()+index,instruction);
    } else {
        instructions.insert(instructions.begin()+index,instruction);
    }
}

vector<Instruction *> MethodRegister::getInstructions() {
    return instructions;
}

vector<Instruction *> MethodRegister::getSubInstructions() {
    vector<Instruction *> *subInstructions=subInstructionsMap[subKey];
    vector<Instruction *> cloneList(*subInstructions);
    return cloneList;
}

void MethodRegister::enableSubInstruction() {
    subKey++;
    subInstructionSwitchMap[subKey]= true;
    subInstructionsMap[subKey]=new vector<Instruction *>();
}

void MethodRegister::disableSubInstruction() {
    subInstructionSwitchMap[subKey]= false;
    clearSubInstructions();
    subKey--;
}

int MethodRegister::getSubtractedSize() {
//    vector<Instruction *> *previousInstructions=subInstructionsMap[subKey-1];
    vector<Instruction *> *subInstructions=subInstructionsMap[subKey];
//    if(previousInstructions){
//        return subInstructions->size()+previousInstructions->size();
//    }
    return subInstructions->size();
}

void MethodRegister::clearSubInstructions(){
    vector<Instruction *> *subInstructions=subInstructionsMap[subKey];
    subInstructions->clear();
    delete subInstructions;
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
    vector<Instruction *> *previousInstructions=subInstructionsMap[subKey-1];
    int originAddress=instructions.size() - 1;
    if(previousInstructions){
        originAddress+=previousInstructions->size();
    }
    return originAddress;
}


int MethodRegister::getExprType(FlyScriptParser::ExprContext *exprContext) {
    if (FlyScriptParser::IntExprContext *intExprContext = dynamic_cast<FlyScriptParser::IntExprContext *>(exprContext)) {
        return ValueType::T_int;
    } else if (FlyScriptParser::StringExprContext *stringExprContext = dynamic_cast<FlyScriptParser::StringExprContext *>(exprContext)) {
        return ValueType::T_string;
    } else if (FlyScriptParser::BooleanTrueExprContext *booleanTrueExprContext = dynamic_cast<FlyScriptParser::BooleanTrueExprContext *>(exprContext)) {
        return ValueType::T_boolean;
    } else if (FlyScriptParser::BooleanFalseExprContext *booleanFalseExprContext = dynamic_cast<FlyScriptParser::BooleanFalseExprContext *>(exprContext)) {
        return ValueType::T_boolean;
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
        string methodName = dynamic_cast<TerminalNodeImpl *>(invokeExprContext->children[0])->getText();
        int returnType = typeInMethodRemember->typeInClassRemember->getMethodReturnType(methodName);
        return returnType;
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
