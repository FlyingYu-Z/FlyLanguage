//
// Created by flying on 2023/1/8.
//
#include "PlusSubTypeInference.h"

PlusSubTypeInference::PlusSubTypeInference(MethodRegister *methodRegister) : methodRegister(methodRegister) {

}

int PlusSubTypeInference::getRealExprType(FlyScriptParser::PlusSubExprContext *plusSubExprContext) {
    auto expr1 = dynamic_cast<FlyScriptParser::ExprContext *>(plusSubExprContext->children[0]);
    auto expr2 = dynamic_cast<FlyScriptParser::ExprContext *>(plusSubExprContext->children[2]);
    if (isIntAndInt(expr1, expr2)) {
        return ValueType::T_int;
    }
    if (isStringAndString(expr1, expr2)) {
        return ValueType::T_string;
    }
    if (isIntAndString(expr1, expr2)) {
        return ValueType::T_string;
    }
    throw CompileException("cannot get the real type for PlusSubExpr");
}

bool PlusSubTypeInference::isIntAndInt(FlyScriptParser::ExprContext *expr1,
                                       FlyScriptParser::ExprContext *expr2) {
    return isSameType(expr1, expr2, ValueType::T_int);
}

bool PlusSubTypeInference::isStringAndString(FlyScriptParser::ExprContext *expr1,
                                             FlyScriptParser::ExprContext *expr2) {
    return isSameType(expr1, expr2, ValueType::T_string);
}

bool PlusSubTypeInference::isSameType(FlyScriptParser::ExprContext *expr1,
                                      FlyScriptParser::ExprContext *expr2, int valueType) {
    int type1 = methodRegister->getExprType(expr1);
    int type2 = methodRegister->getExprType(expr2);
    return type1 == valueType && type2 == valueType;
}

bool PlusSubTypeInference::isIntAndString(FlyScriptParser::ExprContext *expr1,
                                          FlyScriptParser::ExprContext *expr2) {
    return containsTow(expr1, expr2, ValueType::T_int, ValueType::T_string);
}

bool
PlusSubTypeInference::containsTow(FlyScriptParser::ExprContext *expr1,
                                  FlyScriptParser::ExprContext *expr2, int valueType1,
                                  int valueType2) {
    int type1 = methodRegister->getExprType(expr1);
    int type2 = methodRegister->getExprType(expr2);
    if (type1 == type2) {
        return false;
    }
    return (type1 == valueType1 && type2 == valueType2) || (type1 == valueType2 && type2 == valueType1);
}

PlusSubTypeInference::~PlusSubTypeInference() {

}