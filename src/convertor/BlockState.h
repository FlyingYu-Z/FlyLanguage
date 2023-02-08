//
// Created by flying on 2023/2/6.
//

#ifndef FLYLANGUAGE_BLOCKSTATE_H
#define FLYLANGUAGE_BLOCKSTATE_H

#include "Ast2IrConvertor.h"

class BlockState {

protected:
    int usedRegister = 1;
    //variableName,register
    map<string, int> registerMap = map<string, int>();
    bool isChild = false;

public:
    BlockState *parent = nullptr;
    TypeInMethodRemember *typeInMethodRemember;
    PlusSubTypeInference *plusSubTypeInference;

    BlockState();

    virtual ~BlockState();

    void setParent(BlockState *parent);

    void rememberRegister(string variableName, int registerA);

    int getRegister(string variableName);

    int newRegister();

    int newRegister(string variableName);

    bool isFieldVariable(FlyScriptParser::IdentifierExprContext *identifierExprContext);

    bool isFieldVariable(string variableName);

    int getExprType(FlyScriptParser::ExprContext *exprContext);

};


#endif //FLYLANGUAGE_BLOCKSTATE_H
