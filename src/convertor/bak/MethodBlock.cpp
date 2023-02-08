//
// Created by flying on 2023/1/7.
//

#include "Ast2IrConvertor.h"
#include "MethodBlock.h"


MethodBlock::MethodBlock(Ast2IrConvertor *ast2IrConvertor) {
    this->ast2IrConvertor = ast2IrConvertor;
    this->typeInMethodRemember = new TypeInMethodRemember(ast2IrConvertor->typeInClassRemember);
    this->plusSubTypeInference = new PlusSubTypeInference(this);
    this->topMethodBlock = this;
}

MethodBlock *MethodBlock::newChildBlock() {
    auto *methodBlock = new MethodBlock(this->ast2IrConvertor);
    methodBlock->topMethodBlock = this->topMethodBlock;
    methodBlock->parentMethodBlock = this;
    methodBlock->usedRegister = this->usedRegister;
    methodBlock->registerMap = this->registerMap;
    methodBlock->isChild = true;
    methodBlock->typeInMethodRemember = this->typeInMethodRemember;
    methodBlock->plusSubTypeInference = this->plusSubTypeInference;
    return methodBlock;
}

int MethodBlock::addInstruction(Instruction *instruction) {
    instructions.push_back(instruction);
    return currentCodeAddress();
}

void MethodBlock::prepareInstruction(int count) {
    for (int i = 0; i < count; i++) {
        instructions.push_back(new NopInstruction());
        preparedPosList.push_back(instructions.size() - 1);
    }
}

//int MethodBlock::prepareInstruction() {
//    instructions.push_back(new NopInstruction());
//    int index=instructions.size() - 1;
//    return index;
//}

void MethodBlock::patchPreparedInstruction(Instruction *instruction) {
    auto firstIter = preparedPosList.begin();
    int pos = preparedPosList[0];
    NopInstruction *nopInstruction = dynamic_cast<NopInstruction *>(instructions[pos]);
    instructions[pos] = instruction;
    preparedPosList.erase(firstIter);
    delete nopInstruction;
}

void MethodBlock::patchPreparedInstructionForIndex(int index, Instruction *instruction) {
    NopInstruction *nopInstruction = dynamic_cast<NopInstruction *>(instructions[index]);
    instructions[index] = instruction;
    delete nopInstruction;
}

void MethodBlock::addInstruction(int index, Instruction *instruction) {
    instructions.insert(instructions.begin() + index, instruction);
}

void MethodBlock::replaceInstruction(int index, Instruction *instruction) {
    Instruction *instructionOrigin = dynamic_cast<Instruction *>(topMethodBlock->instructions[index]);
    topMethodBlock->instructions[index] = instruction;
    delete instructionOrigin;
}

vector<Instruction *> MethodBlock::getInstructions() {
    return instructions;
}

void MethodBlock::rememberRegister(string variableName, int registerA) {
    if (isChild) {
        parentMethodBlock->registerMap[variableName] = registerA;
    }
    registerMap[variableName] = registerA;
}

int MethodBlock::getRegister(string variableName) {
    if (isChild) {
        return parentMethodBlock->getRegister(variableName);
    }
    return registerMap[variableName];
}

int MethodBlock::newRegister() {
    if (isChild) {
        return parentMethodBlock->newRegister();
    }
    return newRegister("");
}

int MethodBlock::newRegister(string variableName) {
    if (isChild) {
        return parentMethodBlock->newRegister(variableName);
    }
    int registerA = usedRegister++;
    if (!variableName.empty()) {
        rememberRegister(variableName, registerA);
    }
    return registerA;
}

int MethodBlock::previousCodeAddress() {
    return currentCodeAddress() - 1;
}

int MethodBlock::currentCodeAddress() {
    int address = 0;
    MethodBlock *parent = this;
    while (parent != nullptr) {
        address += parent->instructions.size();
        parent = parent->parentMethodBlock;
    }
    return address - 1;
}

int MethodBlock::nextCodeAddress() {
    return currentCodeAddress() + 1;
}

int MethodBlock::getExprType(FlyScriptParser::ExprContext *exprContext) {
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

bool MethodBlock::isFieldVariable(FlyScriptParser::IdentifierExprContext *identifierExprContext) {
    string variableName = identifierExprContext->children[0]->getText();
    return isFieldVariable(variableName);
}

bool MethodBlock::isFieldVariable(string variableName) {
    int fieldType = typeInMethodRemember->typeInClassRemember->getFieldType(variableName);
    return fieldType != 0;
}

int MethodBlock::getBreakCodeAddress() const {
    return breakCodeAddress;
}

void MethodBlock::setIsWhileBlock(bool isWhileBlock) {
    this->isWhileBlock = isWhileBlock;
}

MethodBlock *MethodBlock::findWhileBlock() {
    MethodBlock *parent = this;
    while (parent != nullptr) {
        if (parent->isWhileBlock) {
            return parent;
        }
        parent = parent->parentMethodBlock;
    }
    return nullptr;
}

void MethodBlock::setBreakCodeAddress(int breakCodeAddress) {
    MethodBlock::breakCodeAddress = breakCodeAddress;
}

MethodBlock::~MethodBlock() {
    registerMap.clear();
    instructions.clear();
    preparedPosList.clear();

}


