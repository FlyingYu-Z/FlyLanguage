//
// Created by flying on 2023/1/5.
//

#ifndef FLYLANGUAGE_AST2IRCONVERTOR_H
#define FLYLANGUAGE_AST2IRCONVERTOR_H

#include "antlr4-runtime.h"
#include "ValueType.hpp"
#include "TypeInClassRemember.h"
#include "TypeInMethodRemember.h"
#include "IrMethod.hpp"
#include "MethodRegister.h"


using namespace beingyi;
using namespace antlr4;
using namespace antlr4::tree;


class Ast2IrConvertor {

protected:
    FlyScriptParser::FileContext *tree;

public:
    TypeInClassRemember *typeInClassRemember = new TypeInClassRemember();
    Ast2IrConvertor(FlyScriptParser::FileContext *fileContext);
    ~Ast2IrConvertor();

    static string_view typeContextToString(FlyScriptParser::TypeContext *typeContext);

public:
    FileClass generateFileClass();

};


#endif //FLYLANGUAGE_AST2IRCONVERTOR_H
