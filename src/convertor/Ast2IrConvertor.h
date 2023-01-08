//
// Created by flying on 2023/1/5.
//

#ifndef FLYLANGUAGE_AST2IRCONVERTOR_H
#define FLYLANGUAGE_AST2IRCONVERTOR_H

#include "antlr4-runtime.h"
#include "ValueType.h"
#include "TypeInClassRemember.h"
#include "TypeInMethodRemember.h"
#include "IrMethod.h"
#include "MethodRegister.h"
#include "NonRegisterException.h"

using namespace beingyi;
using namespace antlr4;
using namespace antlr4::tree;


class Ast2IrConvertor {

protected:
    FlyScriptParser::FileContext *tree;

public:
    TypeInClassRemember *typeInClassRemember = new TypeInClassRemember();

    Ast2IrConvertor(FlyScriptParser::FileContext *fileContext);

    void parseBlock(FlyScriptParser::BlockContext blockContext,MethodRegister *methodRegister);

    void parseStat(vector<FlyScriptParser::StmtContext *> rawStmtList,MethodRegister *methodRegister);

    int getExprRegister(FlyScriptParser::ExprContext *exprContext,int type,MethodRegister *methodRegister);

    FileClass generateFileClass();

    ~Ast2IrConvertor();

    static string_view typeContextToString(FlyScriptParser::TypeContext *typeContext);


};


#endif //FLYLANGUAGE_AST2IRCONVERTOR_H
