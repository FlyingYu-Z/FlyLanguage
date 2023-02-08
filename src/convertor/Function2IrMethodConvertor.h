//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_FUNCTION2IRMETHODCONVERTOR_H
#define FLYLANGUAGE_FUNCTION2IRMETHODCONVERTOR_H

#include "Ast2IrConvertor.h"


class Function2IrMethodConvertor {

public:
    Ast2IrConvertor *ast2IrConvertor;
    FlyScriptParser::FunctionContext *functionContext;
    MethodBlock *methodBlock;

    Function2IrMethodConvertor(Ast2IrConvertor *ast2IrConvertor, FlyScriptParser::FunctionContext *functionContext);

    IrMethod *generateIrMethod();

    ~Function2IrMethodConvertor();

private:
    MethodParameter *parseMethodParameter(FlyScriptParser::FunctionParameterContext *functionParameterContext);

};


#endif //FLYLANGUAGE_FUNCTION2IRMETHODCONVERTOR_H
