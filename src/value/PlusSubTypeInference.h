//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_PLUSSUBTYPEINFERENCE_H
#define FLYLANGUAGE_PLUSSUBTYPEINFERENCE_H

#include "Ast2IrConvertor.h"

class MethodRegister;

class Ast2IrConvertor;


class PlusSubTypeInference {

public:
    MethodRegister *methodRegister;

    PlusSubTypeInference(MethodRegister *methodRegister);

    int getRealExprType(FlyScriptParser::PlusSubExprContext *plusSubExprContext);

    bool isIntAndInt(FlyScriptParser::ExprContext *expr1, FlyScriptParser::ExprContext *expr2);

    bool isStringAndString(FlyScriptParser::ExprContext *expr1, FlyScriptParser::ExprContext *expr2);

    bool isSameType(FlyScriptParser::ExprContext *expr1, FlyScriptParser::ExprContext *expr2, int valueType);

    bool isIntAndString(FlyScriptParser::ExprContext *expr1, FlyScriptParser::ExprContext *expr2);

private:
    bool
    containsTow(FlyScriptParser::ExprContext *expr1, FlyScriptParser::ExprContext *expr2, int valueType1,
                int valueType2);

    ~PlusSubTypeInference();
};


#endif //FLYLANGUAGE_PLUSSUBTYPEINFERENCE_H
