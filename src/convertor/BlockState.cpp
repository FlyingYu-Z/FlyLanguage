//
// Created by flying on 2023/2/6.
//

#include "BlockState.h"

BlockState::BlockState() {

}

BlockState::~BlockState() {
    registerMap.clear();
}

void BlockState::setParent(BlockState *parent) {
    BlockState::parent = parent;
    BlockState::isChild = true;
}

void BlockState::rememberRegister(string variableName, int registerA) {
//    if (isChild) {
//        parent->registerMap[variableName] = registerA;
//    }
    registerMap[variableName] = registerA;
}

int BlockState::getRegister(string variableName) {
    if (isChild) {
        int result = registerMap[variableName];
        if (result <= 0) {
            return parent->getRegister(variableName);
        }
        return result;
    }
    return registerMap[variableName];
}

int BlockState::newRegister() {
    if (isChild) {
        return parent->newRegister();
    }
    return newRegister("");
}

int BlockState::newRegister(string variableName) {
    if (isChild) {
        return parent->newRegister(variableName);
    }
    int registerA = usedRegister++;
    if (!variableName.empty()) {
        rememberRegister(variableName, registerA);
    }
    return registerA;
}

int BlockState::getExprType(FlyScriptParser::ExprContext *exprContext) {
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
    } else if (FlyScriptParser::ParensExprContext *parensExprContext = dynamic_cast<FlyScriptParser::ParensExprContext *>(exprContext)) {
        FlyScriptParser::ExprContext *exprInParens = dynamic_cast<FlyScriptParser::ExprContext *>(parensExprContext->children[1]);
        return getExprType(exprInParens);
    }
    throw CompileException("unknown expr");
}

bool BlockState::isFieldVariable(FlyScriptParser::IdentifierExprContext *identifierExprContext) {
    string variableName = identifierExprContext->children[0]->getText();
    return isFieldVariable(variableName);
}

bool BlockState::isFieldVariable(string variableName) {
    int fieldType = typeInMethodRemember->typeInClassRemember->getFieldType(variableName);
    return fieldType != 0;
}
