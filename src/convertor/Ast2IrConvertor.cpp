//
// Created by flying on 2023/1/7.
//
#include "Ast2IrConvertor.h"


Ast2IrConvertor::Ast2IrConvertor(FlyScriptParser::FileContext *fileContext) {
    this->tree = fileContext;
    MethodRegister methodRegister = MethodRegister(this);

    auto opcode = Opcode::ConstString;

    printf("opcode:%s\n", Opcode::getOpcodeName(opcode));
    try {
        auto *ins = new ConstStringInstruction(1, "hello world");
        //auto ins2 = ConstIntInstruction(1, 356);

        printf("ins opcode:%d\n", ins->getOpcode());

        const char *data = dump(ins).data();
        printf("ins:%s\n", data);
        delete data;
        data = NULL;
        //printf("ins2:%s\n",ins2.toString().data());
    } catch (std::exception &e) {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
}

void parseBlock(FlyScriptParser::BlockContext blockContext, MethodRegister *methodRegister) {
    vector<FlyScriptParser::StmtContext> rawStatList = vector<FlyScriptParser::StmtContext>();
    for (ParseTree *child: blockContext.children) {
        if (FlyScriptParser::StmtContext *stmtContext = dynamic_cast<FlyScriptParser::StmtContext *>(child)) {

        }
    }
}

void Ast2IrConvertor::parseStat(vector<FlyScriptParser::StmtContext *> rawStmtList, MethodRegister *methodRegister) {
    for (FlyScriptParser::StmtContext *stmtContext: rawStmtList) {
        if (FlyScriptParser::FieldContext *fieldContext = dynamic_cast<FlyScriptParser::FieldContext *>(stmtContext)) {
            string_view type = Ast2IrConvertor::typeContextToString(
                    dynamic_cast<FlyScriptParser::TypeContext *>(fieldContext->children[0]));
            string_view fieldName = dynamic_cast<TerminalNodeImpl *>(fieldContext->children[1])->getText();

        }
    }
}

int
Ast2IrConvertor::getExprRegister(FlyScriptParser::ExprContext *exprContext, int type, MethodRegister *methodRegister) {
    if (FlyScriptParser::IdentifierExprContext *identifierExprContext = dynamic_cast<FlyScriptParser::IdentifierExprContext *>(exprContext)) {
        string_view variableName = identifierExprContext->children[0]->getText();
        if (methodRegister->isFieldVariable(variableName)) {
            int getFieldRegister = methodRegister->newRegister();
            methodRegister->addInstruction(GetFieldInstruction(getFieldRegister, variableName));
            return getFieldRegister;
        } else {
            int variableRegister = methodRegister->getRegister(variableName);
            if (!variableRegister) {
                throw NonRegisterException(variableName.data());
            }
            return variableRegister;
        }
    }

}

FileClass Ast2IrConvertor::generateFileClass() {
    FileClass fileClass = FileClass();
    auto rawFieldList = vector<FlyScriptParser::FieldContext *>();
    auto rawStmtList = vector<FlyScriptParser::StmtContext *>();
    auto rawFunctionList = vector<FlyScriptParser::FunctionContext *>();

    for (int i = 0; i < tree->children.size(); i++) {
        ParseTree *childTree = tree->children[i];
        if (FlyScriptParser::FunctionContext *functionContext = dynamic_cast<FlyScriptParser::FunctionContext *>(childTree)) {
            string_view returnType = Ast2IrConvertor::typeContextToString(
                    dynamic_cast<FlyScriptParser::TypeContext *>(functionContext->children[0]));
            string_view methodName = dynamic_cast<TerminalNodeImpl *>(functionContext->children[1])->getText();
            typeInClassRemember->putMethodReturnType(methodName, ValueType::getType(returnType));
//            printf("return type:%s -> %d\n", returnType.data(),ValueType::getType(returnType));
//            printf("methodName:%s\n", methodName.data());
            rawFunctionList.push_back(functionContext);
        } else {
            if (FlyScriptParser::FieldContext *fieldContext = dynamic_cast<FlyScriptParser::FieldContext *>(childTree)) {
                string_view type = Ast2IrConvertor::typeContextToString(
                        dynamic_cast<FlyScriptParser::TypeContext *>(fieldContext->children[0]));
                string_view fieldName = dynamic_cast<TerminalNodeImpl *>(fieldContext->children[1])->getText();
                typeInClassRemember->putFieldType(fieldName, ValueType::getType(type));
                rawFieldList.push_back(fieldContext);
            }
            rawStmtList.push_back(dynamic_cast<FlyScriptParser::StmtContext *>(childTree));
        }
    }

    MethodRegister *mainMethodRegister = new MethodRegister(this);
    parseStat(rawStmtList, mainMethodRegister);
    IrMethod mainMethod = IrMethod(ValueType::T_void, "main", vector<MethodParameter>(),
                                   mainMethodRegister->getInstructions());
    fileClass.addMethod(mainMethod);

    delete mainMethodRegister;
    return fileClass;
}

Ast2IrConvertor::~Ast2IrConvertor() {

}

string_view Ast2IrConvertor::typeContextToString(FlyScriptParser::TypeContext *typeContext) {
    auto typeValue = dynamic_cast<TerminalNodeImpl *>(typeContext->children[0])->symbol->getType();
    return ValueType::getName(typeValue);
}