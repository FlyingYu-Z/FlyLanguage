//
// Created by flying on 2023/1/8.
//

#include "Function2IrMethodConvertor.h"

Function2IrMethodConvertor::Function2IrMethodConvertor(Ast2IrConvertor *ast2IrConvertor,
                                                       FlyScriptParser::FunctionContext *functionContext)
        : ast2IrConvertor(ast2IrConvertor), functionContext(functionContext) {

    this->methodRegister = new MethodRegister(ast2IrConvertor);

}

IrMethod Function2IrMethodConvertor::generateIrMethod() {
    string returnType = Ast2IrConvertor::typeContextToString(
            dynamic_cast<FlyScriptParser::TypeContext *>(functionContext->children[0]));
    string methodName = dynamic_cast<TerminalNodeImpl *>(functionContext->children[1])->getText();
    auto functionParameters = dynamic_cast<FlyScriptParser::FunctionParametersContext *>(functionContext->children[3]);
    auto methodParameterList = vector<MethodParameter>();
    for(ParseTree *childTree:functionParameters->children){
        auto *functionParameterContext=dynamic_cast<FlyScriptParser::FunctionParameterContext *>(childTree);
        auto methodParameter= parseMethodParameter(functionParameterContext);
        methodParameterList.push_back(methodParameter);
    }
    for(int i=0;i<methodParameterList.size();i++){
        MethodParameter methodParameter=methodParameterList[i];
        string paramName=methodParameter.getName();
        int paramType=methodParameter.getType();
        int registerA=methodRegister->newRegister(paramName);
        int index=i;
        methodRegister->addInstruction(new ConstParamInstruction(registerA,index));
        methodRegister->typeInMethodRemember->putVariableType(paramName,paramType);
        methodRegister->rememberRegister(paramName,registerA);
    }

    auto block=dynamic_cast<FlyScriptParser::BlockContext *>(functionContext->children[5]);
    ast2IrConvertor->parseBlock(block,methodRegister);

    auto irMethod= IrMethod(ValueType::getType(returnType),methodName,methodParameterList,methodRegister->getInstructions());
    return irMethod;
}

Function2IrMethodConvertor::~Function2IrMethodConvertor() {

}

MethodParameter
Function2IrMethodConvertor::parseMethodParameter(FlyScriptParser::FunctionParameterContext *functionParameterContext) {
    string typeString = Ast2IrConvertor::typeContextToString(
            dynamic_cast<FlyScriptParser::TypeContext *>(functionParameterContext->children[0]));
    string name = dynamic_cast<TerminalNodeImpl *>(functionParameterContext->children[1])->getText().c_str();
    int type = ValueType::getType(typeString);
    return MethodParameter(name, type);
}