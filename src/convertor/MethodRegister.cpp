//
// Created by flying on 2023/1/7.
//

#include "Ast2IrConvertor.h"
#include "MethodRegister.h"


MethodRegister::MethodRegister(Ast2IrConvertor *ast2IrConvertor) {
    this->typeInMethodRemember = new TypeInMethodRemember(ast2IrConvertor->typeInClassRemember);
    this->plusSubTypeInference = new PlusSubTypeInference(this);
}

MethodRegister::MethodRegister(MethodRegister *methodRegister) {
    this->parentMethodRegister = methodRegister;
    this->usedRegister = methodRegister->usedRegister;
    this->registerMap = methodRegister->registerMap;
    this->isChild = true;
    this->continueCodeAddress = methodRegister->currentCodeAddress();
    this->typeInMethodRemember = methodRegister->typeInMethodRemember;
    this->plusSubTypeInference = methodRegister->plusSubTypeInference;
}

int MethodRegister::addInstruction(Instruction *instruction) {
    instructions.push_back(instruction);
    return currentCodeAddress() -1;
}

void MethodRegister::prepareInstruction(int count) {
    for(int i=0;i<count;i++) {
        instructions.push_back(new NopInstruction());
        preparedPosList.push_back(instructions.size()-1);
    }
}

int MethodRegister::prepareInstruction() {
    instructions.push_back(new NopInstruction());
    int index=instructions.size() - 1;
    return index;
}

void MethodRegister::patchPreparedInstruction(Instruction *instruction) {
    auto firstIter = preparedPosList.begin();
    int pos = preparedPosList[0];
    NopInstruction *nopInstruction= dynamic_cast<NopInstruction *>(instructions[pos]);
    instructions[pos] = instruction;
    preparedPosList.erase(firstIter);

    delete nopInstruction;
}

void MethodRegister::patchPreparedInstructionForIndex(int index, Instruction *instruction) {
    NopInstruction *nopInstruction= dynamic_cast<NopInstruction *>(instructions[index]);
    instructions[index] = instruction;
    delete nopInstruction;
}

void MethodRegister::addInstruction(int index, Instruction *instruction) {
    instructions.insert(instructions.begin() + index, instruction);
}

void MethodRegister::replaceInstruction(int index, Instruction *instruction){
    //Instruction *instructionOrigin= dynamic_cast<Instruction *>(instructions[index]);
    delete instructions[index];
    instructions[index]=instruction;
    //delete instructionOrigin;
}

vector<Instruction *> MethodRegister::getInstructions() {
    return instructions;
}

void MethodRegister::rememberRegister(string variableName, int registerA) {
    if (isChild) {
        parentMethodRegister->registerMap[variableName] = registerA;
    }
    registerMap[variableName] = registerA;
}

int MethodRegister::getRegister(string variableName) {
    if (isChild) {
        return parentMethodRegister->getRegister(variableName);
    }
    return registerMap[variableName];
}

int MethodRegister::newRegister() {
    if (isChild) {
        return parentMethodRegister->newRegister();
    }
    return newRegister("");
}

int MethodRegister::newRegister(string variableName) {
    if (isChild) {
        return parentMethodRegister->newRegister(variableName);
    }
    int registerA = usedRegister++;
    if (!variableName.empty()) {
        rememberRegister(variableName, registerA);
    }
    return registerA;
}

int MethodRegister::currentCodeAddress() {
    if (isChild) {
        return continueCodeAddress + instructions.size();
    }
    return instructions.size();
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
