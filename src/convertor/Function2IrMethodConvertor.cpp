//
// Created by flying on 2023/1/8.
//

#include "Function2IrMethodConvertor.h"

Function2IrMethodConvertor::Function2IrMethodConvertor(Ast2IrConvertor *ast2IrConvertor,
                                                       FlyScriptParser::FunctionContext *functionContext)
        : ast2IrConvertor(ast2IrConvertor), functionContext(functionContext) {

    this->methodBlock = new MethodBlock(ast2IrConvertor->typeInClassRemember);

}

IrMethod *Function2IrMethodConvertor::generateIrMethod() {
    string returnTypeString = Ast2IrConvertor::typeContextToString(
            dynamic_cast<FlyScriptParser::TypeContext *>(functionContext->children[0]));
    int returnType = ValueType::getType(returnTypeString);
    string methodName = dynamic_cast<TerminalNodeImpl *>(functionContext->children[1])->getText();
    auto methodParameterList = vector<MethodParameter *>();
    auto functionParameters = dynamic_cast<FlyScriptParser::FunctionParametersContext *>(functionContext->children[3]);
    if (functionParameters) {
        for (ParseTree *childTree: functionParameters->children) {
            if (auto *functionParameterContext = dynamic_cast<FlyScriptParser::FunctionParameterContext *>(childTree)) {
                auto *methodParameter = parseMethodParameter(functionParameterContext);
                methodParameterList.push_back(methodParameter);
            } else if (TerminalNodeImpl *splitSymbol = dynamic_cast<TerminalNodeImpl *>(childTree)) {
                string symbol = splitSymbol->getText();
                if (strcmp(symbol.data(), ",") != 0) {
                    throw CompileException("splitSymbol must be ','");
                }
            } else {
                throw CompileException("childTree must be FunctionParameterContext");
            }
        }
    }
    for (int i = 0; i < methodParameterList.size(); i++) {
        MethodParameter *methodParameter = methodParameterList[i];
        string paramName = methodParameter->getName();
        int paramType = methodParameter->getType();
        int registerA = methodBlock->state->newRegister(paramName);
        int index = i;
        methodBlock->addInstruction(new ConstParamInstruction(registerA, index));
        methodBlock->state->typeInMethodRemember->putVariableType(paramName, paramType);
        methodBlock->state->rememberRegister(paramName, registerA);
    }

    auto block = dynamic_cast<FlyScriptParser::BlockContext *>(functionContext->children.at(functionContext->children.size() - 1));
    ast2IrConvertor->parseBlock(block, methodBlock);
    if (returnType == ValueType::T_void) {
        methodBlock->addInstruction(new ReturnInstruction());
    }
    auto irMethod = new IrMethod(returnType, methodName, methodParameterList, methodBlock->getInstructions());
    return irMethod;
}

Function2IrMethodConvertor::~Function2IrMethodConvertor() {
    delete methodBlock;
}

MethodParameter
*Function2IrMethodConvertor::parseMethodParameter(FlyScriptParser::FunctionParameterContext *functionParameterContext) {
    string typeString = Ast2IrConvertor::typeContextToString(
            dynamic_cast<FlyScriptParser::TypeContext *>(functionParameterContext->children[0]));
    string name = dynamic_cast<TerminalNodeImpl *>(functionParameterContext->children[1])->getText().c_str();
    int type = ValueType::getType(typeString);
    return new MethodParameter(name, type);
}