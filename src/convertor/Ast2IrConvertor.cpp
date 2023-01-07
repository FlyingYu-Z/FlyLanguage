//
// Created by flying on 2023/1/7.
//
#include "Ast2IrConvertor.h"


Ast2IrConvertor::Ast2IrConvertor(FlyScriptParser::FileContext *fileContext) {
    this->tree = fileContext;
    MethodRegister methodRegister = MethodRegister(this);

    auto opcode = Opcode::ConstString;

    printf("opcode:%s\n", Opcode::getName(opcode));
    try {
        auto ins = ConstStringInstruction(1, "hello world");
        //auto ins2 = ConstIntInstruction(1, 356);

        printf("ins opcode:%d\n", ins.getOpcode());

        const char *data = ins.toString().data();
        printf("ins:%s\n", data);
        delete data;
        data = NULL;
        //printf("ins2:%s\n",ins2.toString().data());
    } catch (std::exception &e) {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
}

string_view Ast2IrConvertor::typeContextToString(FlyScriptParser::TypeContext *typeContext){
    auto typeValue=dynamic_cast<TerminalNodeImpl *>(typeContext->children[0])->symbol->getType();
    return ValueType::getName(typeValue);
}


FileClass Ast2IrConvertor::generateFileClass() {
    FileClass fileClass = FileClass();
    auto rawFieldList = vector<FlyScriptParser::FieldContext>();
    auto rawStatList = vector<FlyScriptParser::StatContext>();
    auto rawFunctionList = vector<FlyScriptParser::FunctionContext>();

    for (int i=0;i<tree->children.size();i++) {
        ParseTree *childTree=tree->children[i];
        if(FlyScriptParser::FunctionContext* functionContext = dynamic_cast<FlyScriptParser::FunctionContext*>(childTree)) {
            FlyScriptParser::TypeContext *returnType= dynamic_cast<FlyScriptParser::TypeContext *>(functionContext->children[0]);
            string_view typeString= Ast2IrConvertor::typeContextToString(returnType);
            printf("return type:%s",typeString.data());
        }else{
            if(FlyScriptParser::FieldContext* fieldContext = dynamic_cast<FlyScriptParser::FieldContext*>(childTree)) {

            }
        }
    }

    return fileClass;
}

Ast2IrConvertor::~Ast2IrConvertor() {

}