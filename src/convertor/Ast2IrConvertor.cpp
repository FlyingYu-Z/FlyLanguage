//
// Created by flying on 2023/1/7.
//
#include "Ast2IrConvertor.h"


Ast2IrConvertor::Ast2IrConvertor(FlyScriptParser::FileContext *fileContext) {
    this->tree = fileContext;
}

void Ast2IrConvertor::parseBlock(FlyScriptParser::BlockContext *blockContext, MethodRegister *methodRegister) {
    vector<ParseTree *> rawStatList = vector<ParseTree *>();
    for (ParseTree *child: blockContext->children) {
        if (FlyScriptParser::StmtContext *stmtContext = dynamic_cast<FlyScriptParser::StmtContext *>(child)) {
            rawStatList.push_back(stmtContext);
        }
    }
    parseStmt(rawStatList, methodRegister);
}

void Ast2IrConvertor::parseStmt(vector<ParseTree *> rawStmtList, MethodRegister *methodRegister) {
    for (ParseTree *stmtContext: rawStmtList) {
        if (FlyScriptParser::FieldContext *fieldContext = dynamic_cast<FlyScriptParser::FieldContext *>(stmtContext)) {
            string typeString = Ast2IrConvertor::typeContextToString(
                    dynamic_cast<FlyScriptParser::TypeContext *>(fieldContext->children[0]));
            int type = ValueType::getType(typeString);
            string fieldName = dynamic_cast<TerminalNodeImpl *>(fieldContext->children[1])->getText();
            auto valueExpr = dynamic_cast<FlyScriptParser::ExprContext *>(fieldContext->children[3]);
            int registerA = getExprRegister(valueExpr, type, methodRegister);
            methodRegister->rememberRegister(fieldName, registerA);
            typeInClassRemember->putFieldType(fieldName, type);
            methodRegister->addInstruction(new SetFieldInstruction(registerA, fieldName));
        } else if (FlyScriptParser::VarStmtContext *varStmtContext = dynamic_cast<FlyScriptParser::VarStmtContext *>(stmtContext)) {
            string typeString = Ast2IrConvertor::typeContextToString(
                    dynamic_cast<FlyScriptParser::TypeContext *>(varStmtContext->children[0]));
            int type = ValueType::getType(typeString);
            string variableName = dynamic_cast<TerminalNodeImpl *>(varStmtContext->children[1])->getText();
            auto valueExpr = dynamic_cast<FlyScriptParser::ExprContext *>(varStmtContext->children[3]);
            int registerA = getExprRegister(valueExpr, type, methodRegister);
            methodRegister->rememberRegister(variableName, registerA);
            methodRegister->typeInMethodRemember->putVariableType(variableName, type);
        } else if (FlyScriptParser::AssignStmtContext *assignStmtContext = dynamic_cast<FlyScriptParser::AssignStmtContext *>(stmtContext)) {
            string variableName = dynamic_cast<FlyScriptParser::IdentifierExprContext *>(assignStmtContext->children[0])->getText();
            auto valueExpr = dynamic_cast<FlyScriptParser::ExprContext *>(assignStmtContext->children[2]);
            int exprType = methodRegister->getExprType(valueExpr);
            if (methodRegister->isFieldVariable(variableName)) {
                int originType = typeInClassRemember->getFieldType(variableName);
                if (exprType != originType) {
                    throw CompileException(
                            fmt::sprintf("the origin file type is %d,but new field type is %d", originType, exprType));
                }
                //val oldRegister = methodRegister.getRegister(variableName) ?: throw NonRegisterException(variableName)
                int newRegister = getExprRegister(valueExpr, originType, methodRegister);
                methodRegister->addInstruction(new SetFieldInstruction(newRegister, variableName));
            } else {
                int originType = typeInClassRemember->getFieldType(variableName);
                if (exprType != originType) {
                    throw CompileException(
                            fmt::sprintf("the origin file type is %d,but new field type is %d", originType, exprType));
                }
                int oldRegister = methodRegister->getRegister(variableName);
                if (!oldRegister) {
                    throw NonRegisterException(variableName.data());
                }
                int newRegister = getExprRegister(valueExpr, originType, methodRegister);
                methodRegister->addInstruction(new MoveInstruction(oldRegister, newRegister));
            }
        } else if (FlyScriptParser::InvokeStmtContext *invokeStmtContext = dynamic_cast<FlyScriptParser::InvokeStmtContext *>(stmtContext)) {
            auto childStmt = invokeStmtContext->children[0];
            if (FlyScriptParser::InvokeExprContext *invokeExprContext = dynamic_cast<FlyScriptParser::InvokeExprContext *>(childStmt)) {
                string methodName = dynamic_cast<TerminalNodeImpl *>(invokeExprContext->children[0])->getText();
                auto exprListContext = dynamic_cast<FlyScriptParser::ExprListContext *>(invokeExprContext->children[2]);

                vector<int> paramRegList = vector<int>();
                for (int i = 0; i < exprListContext->children.size(); i++) {
                    if (FlyScriptParser::ExprContext *childExpr = dynamic_cast<FlyScriptParser::ExprContext *>(exprListContext->children[i])) {
                        int exprType = methodRegister->getExprType(childExpr);
                        int reg = getExprRegister(childExpr, exprType, methodRegister);
                        paramRegList.push_back(reg);
                    } else {
                        throw CompileException("childExpr must be ExprContext");
                    }
                }
                methodRegister->addInstruction(new InvokeInstruction(methodName, paramRegList));
            } else {
                throw CompileException("InvokeStmtContext must be InvokeExprContext");
            }
        } else if (FlyScriptParser::IfElseStmtContext *ifElseStmtContext = dynamic_cast<FlyScriptParser::IfElseStmtContext *>(stmtContext)) {
            auto expr = dynamic_cast<FlyScriptParser::ExprContext *>(ifElseStmtContext->children[2]);
            int finalRegister = 0;
            if (FlyScriptParser::OrBooleanExprContext *orBooleanExprContext = dynamic_cast<FlyScriptParser::OrBooleanExprContext *>(ifElseStmtContext)) {
                finalRegister = 0;
            } else {
                finalRegister = getExprRegister(expr, ValueType::T_boolean, methodRegister);
            }
            auto *block1 = dynamic_cast<FlyScriptParser::BlockContext *>(ifElseStmtContext->children[4]);
            auto *block2 = dynamic_cast<FlyScriptParser::BlockContext *>(ifElseStmtContext->children[6]);

            methodRegister->enableSubInstruction();
            parseBlock(block1, methodRegister);
            vector<Instruction *> block1Instructions = methodRegister->getSubInstructions();
            methodRegister->disableSubInstruction();

            methodRegister->enableSubInstruction();
            parseBlock(block2, methodRegister);
            vector<Instruction *> block2Instructions = methodRegister->getSubInstructions();
            methodRegister->disableSubInstruction();

            int block1StartAddress = methodRegister->currentCodeAddress() + block2Instructions.size() + 3;
            int block1EndAddress = block1StartAddress + block1Instructions.size();
            block2Instructions.push_back(new GotoInstruction(block1EndAddress));
            methodRegister->addInstruction(new IfInstruction(finalRegister, block1StartAddress));

            for (Instruction *instruction: block2Instructions) {
                methodRegister->addInstruction(instruction);
            }
            for (Instruction *instruction: block1Instructions) {
                methodRegister->addInstruction(instruction);
            }

        }


    }
}

int
Ast2IrConvertor::getExprRegister(FlyScriptParser::ExprContext *exprContext, int type, MethodRegister *methodRegister) {
    if (FlyScriptParser::IdentifierExprContext *identifierExprContext = dynamic_cast<FlyScriptParser::IdentifierExprContext *>(exprContext)) {
        string variableName = identifierExprContext->children[0]->getText();
        if (methodRegister->isFieldVariable(variableName)) {
            int getFieldRegister = methodRegister->newRegister();
            methodRegister->addInstruction(new GetFieldInstruction(getFieldRegister, variableName));
            return getFieldRegister;
        } else {
            int variableRegister = methodRegister->getRegister(variableName);
            if (!variableRegister) {
                throw NonRegisterException(variableName.data());
            }
            return variableRegister;
        }
    } else if (FlyScriptParser::PlusSubExprContext *plusSubExprContext = dynamic_cast<FlyScriptParser::PlusSubExprContext *>(exprContext)) {
        auto expr1 = dynamic_cast<FlyScriptParser::ExprContext *>(plusSubExprContext->children[0]);
        auto symbol = dynamic_cast<TerminalNodeImpl *>(plusSubExprContext->children[1])->getText();
        auto expr2 = dynamic_cast<FlyScriptParser::ExprContext *>(plusSubExprContext->children[2]);
        if (strcmp(symbol.data(), "+") == 0) {
            auto type1 = methodRegister->getExprType(expr1);
            auto type2 = methodRegister->getExprType(expr2);
            auto register1 = getExprRegister(expr1, type1, methodRegister);
            auto register2 = getExprRegister(expr2, type2, methodRegister);
            methodRegister->addInstruction(new PlusInstruction(register1, register2));
            int resultRegister = methodRegister->newRegister();
            methodRegister->addInstruction(new MoveResultObjectInstruction(resultRegister));
            return resultRegister;
        } else if (strcmp(symbol.data(), "-") == 0) {
            if (methodRegister->plusSubTypeInference->isStringAndString(expr1, expr2)) {
                throw RuntimeException("Strings cannot be subtracted");
            }
            if (methodRegister->plusSubTypeInference->isIntAndString(expr1, expr2)) {
                throw RuntimeException("Strings and numbers cannot be added");
            }
        }
    } else if (FlyScriptParser::BooleanExprContext *booleanExprContext = dynamic_cast<FlyScriptParser::BooleanExprContext *>(exprContext)) {
        auto expr1 = dynamic_cast<FlyScriptParser::ExprContext *>(booleanExprContext->children[0]);
        auto symbol = dynamic_cast<FlyScriptParser::JudgeSymbolContext *>(booleanExprContext->children[1])->getText();
        auto expr2 = dynamic_cast<FlyScriptParser::ExprContext *>(booleanExprContext->children[2]);
        auto type1 = methodRegister->getExprType(expr1);
        auto type2 = methodRegister->getExprType(expr2);
        auto register1 = getExprRegister(expr1, type1, methodRegister);
        auto register2 = getExprRegister(expr2, type2, methodRegister);
        methodRegister->addInstruction(
                new BoolInstruction(register1, BoolInstruction::getSymbolByName(symbol), register2));
        int resultRegister = methodRegister->newRegister();
        methodRegister->addInstruction(new MoveResultObjectInstruction(resultRegister));
        return resultRegister;
    }
    switch (type) {
        case ValueType::T_int: {
            if (FlyScriptParser::IntExprContext *intExprContext = dynamic_cast<FlyScriptParser::IntExprContext *>(exprContext)) {
                int registerA = methodRegister->newRegister();
                string text = intExprContext->getText();
                methodRegister->addInstruction(new ConstIntInstruction(registerA, stoi(text.data())));
                return registerA;
            }
        }
        case ValueType::T_string: {
            if (FlyScriptParser::StringExprContext *stringExprContext = dynamic_cast<FlyScriptParser::StringExprContext *>(exprContext)) {
                int registerA = methodRegister->newRegister();
                string text = stringExprContext->children[1]->getText();
                methodRegister->addInstruction(new ConstStringInstruction(registerA, text.data()));
                return registerA;
            }
        }
    }
    throw CompileException("this exprContext is support");
}

FileClass Ast2IrConvertor::generateFileClass() {
    FileClass fileClass = FileClass();
    auto rawFieldList = vector<FlyScriptParser::FieldContext *>();
    auto rawStmtList = vector<ParseTree *>();
    auto rawFunctionList = vector<FlyScriptParser::FunctionContext *>();

    for (int i = 0; i < tree->children.size(); i++) {
        ParseTree *childTree = tree->children[i];
        if (FlyScriptParser::FunctionContext *functionContext = dynamic_cast<FlyScriptParser::FunctionContext *>(childTree)) {
            string returnType = Ast2IrConvertor::typeContextToString(
                    dynamic_cast<FlyScriptParser::TypeContext *>(functionContext->children[0]));
            string methodName = dynamic_cast<TerminalNodeImpl *>(functionContext->children[1])->getText();
            typeInClassRemember->putMethodReturnType(methodName, ValueType::getType(returnType));
//            printf("return type:%s -> %d\n", returnType.data(),ValueType::getType(returnType));
//            printf("methodName:%s\n", methodName.data());
            rawFunctionList.push_back(functionContext);
        } else {
            if (FlyScriptParser::FieldContext *fieldContext = dynamic_cast<FlyScriptParser::FieldContext *>(childTree)) {
                rawFieldList.push_back(fieldContext);
            }
            rawStmtList.push_back(childTree);
        }
    }

    auto *mainMethodRegister = new MethodRegister(this);

    for (FlyScriptParser::FieldContext *fieldContext: rawFieldList) {
        string typeString = Ast2IrConvertor::typeContextToString(
                dynamic_cast<FlyScriptParser::TypeContext *>(fieldContext->children[0]));
        string fieldName = dynamic_cast<TerminalNodeImpl *>(fieldContext->children[1])->getText().c_str();
        int type = ValueType::getType(typeString);
        typeInClassRemember->putFieldType(fieldName, type);
        fileClass.addField(IrField(fieldName, type));
    }

    parseStmt(rawStmtList, mainMethodRegister);
    IrMethod mainMethod = IrMethod(ValueType::T_void, "main", vector<MethodParameter>(),
                                   mainMethodRegister->getInstructions());
    fileClass.addMethod(mainMethod);

    for (FlyScriptParser::FunctionContext *functionContext: rawFunctionList) {
        auto function2IrMethodConvertor = Function2IrMethodConvertor(this, functionContext);
        auto method = function2IrMethodConvertor.generateIrMethod();
        fileClass.addMethod(method);
    }

    delete mainMethodRegister;
    return fileClass;
}

Ast2IrConvertor::~Ast2IrConvertor() {

}

string Ast2IrConvertor::typeContextToString(FlyScriptParser::TypeContext *typeContext) {
    auto typeValue = dynamic_cast<TerminalNodeImpl *>(typeContext->children[0])->symbol->getType();
    return ValueType::getName(typeValue);
}