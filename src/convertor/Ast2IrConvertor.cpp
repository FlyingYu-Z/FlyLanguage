//
// Created by flying on 2023/1/7.
//
#include "Ast2IrConvertor.h"

Ast2IrConvertor::Ast2IrConvertor(FlyScriptParser::FileContext *fileContext) {
    this->tree = fileContext;
}

void
Ast2IrConvertor::parseBlock(FlyScriptParser::BlockContext *blockContext, MethodBlock *methodBlock) {
    vector<ParseTree *> rawStatList = vector<ParseTree *>();
    for (ParseTree *child: blockContext->children) {
        if (FlyScriptParser::StmtContext *stmtContext = dynamic_cast<FlyScriptParser::StmtContext *>(child)) {
            rawStatList.push_back(stmtContext);
        }
    }
    parseStmt(rawStatList, methodBlock);
}

void Ast2IrConvertor::parseStmt(vector<ParseTree *> rawStmtList, MethodBlock *methodBlock) {
    for (ParseTree *stmtContext: rawStmtList) {
        if (FlyScriptParser::FieldContext *fieldContext = dynamic_cast<FlyScriptParser::FieldContext *>(stmtContext)) {
            string typeString = Ast2IrConvertor::typeContextToString(
                    dynamic_cast<FlyScriptParser::TypeContext *>(fieldContext->children[0]));
            int type = ValueType::getType(typeString);
            string fieldName = dynamic_cast<TerminalNodeImpl *>(fieldContext->children[1])->getText();
            auto valueExpr = dynamic_cast<FlyScriptParser::ExprContext *>(fieldContext->children[3]);
            ExprResult exprResultA = getExprResult(valueExpr, type, methodBlock);
            exprResultA.commitInstruction(methodBlock);
            int registerA = exprResultA.resultRegister;
            methodBlock->state->rememberRegister(fieldName, registerA);
            typeInClassRemember->putFieldType(fieldName, type);
            methodBlock->addInstruction(new SetFieldInstruction(registerA, fieldName));
        } else if (FlyScriptParser::VarStmtContext *varStmtContext = dynamic_cast<FlyScriptParser::VarStmtContext *>(stmtContext)) {
            string typeString = Ast2IrConvertor::typeContextToString(
                    dynamic_cast<FlyScriptParser::TypeContext *>(varStmtContext->children[0]));
            int type = ValueType::getType(typeString);
            string variableName = dynamic_cast<TerminalNodeImpl *>(varStmtContext->children[1])->getText();
            auto valueExpr = dynamic_cast<FlyScriptParser::ExprContext *>(varStmtContext->children[3]);
            ExprResult exprResultA = getExprResult(valueExpr, type, methodBlock);
            exprResultA.commitInstruction(methodBlock);
            int registerA = exprResultA.resultRegister;
            methodBlock->state->rememberRegister(variableName, registerA);
            methodBlock->state->typeInMethodRemember->putVariableType(variableName, type);
        } else if (FlyScriptParser::AssignStmtContext *assignStmtContext = dynamic_cast<FlyScriptParser::AssignStmtContext *>(stmtContext)) {
            string variableName = dynamic_cast<FlyScriptParser::IdentifierExprContext *>(assignStmtContext->children[0])->getText();
            auto valueExpr = dynamic_cast<FlyScriptParser::ExprContext *>(assignStmtContext->children[2]);
            int exprType = methodBlock->state->getExprType(valueExpr);
            if (methodBlock->state->isFieldVariable(variableName)) {
                int originType = typeInClassRemember->getFieldType(variableName);
                if (exprType != originType) {
                    throw CompileException(
                            fmt::sprintf("the origin file type is %d,but new field type is %d", originType, exprType));
                }
                //val oldRegister = methodBlock.getRegister(variableName) ?: throw NonRegisterException(variableName)
                ExprResult exprResultA = getExprResult(valueExpr, originType, methodBlock);
                exprResultA.commitInstruction(methodBlock);
                int newRegister = exprResultA.resultRegister;
                methodBlock->addInstruction(new SetFieldInstruction(newRegister, variableName));
            } else {
                int originType = methodBlock->state->typeInMethodRemember->getVariableType(variableName);
                if (exprType != originType) {
                    throw CompileException(
                            fmt::sprintf("the origin file type is %d,but new field type is %d", originType, exprType));
                }
                int oldRegister = methodBlock->state->getRegister(variableName);
                if (!oldRegister) {
                    throw NonRegisterException(variableName.data());
                }
                ExprResult exprResultA = getExprResult(valueExpr, originType, methodBlock);
                exprResultA.commitInstruction(methodBlock);
                int newRegister = exprResultA.resultRegister;
                methodBlock->addInstruction(new MoveInstruction(oldRegister, newRegister));
            }
        } else if (FlyScriptParser::InvokeStmtContext *invokeStmtContext = dynamic_cast<FlyScriptParser::InvokeStmtContext *>(stmtContext)) {
            auto childStmt = invokeStmtContext->children[0];
            if (FlyScriptParser::InvokeExprContext *invokeExprContext = dynamic_cast<FlyScriptParser::InvokeExprContext *>(childStmt)) {
                //string methodName = dynamic_cast<TerminalNodeImpl *>(invokeExprContext->children[0])->getText();
                ExprResult exprResultA = getExprResult(invokeExprContext,
                                                       methodBlock->state->getExprType(invokeExprContext), methodBlock);
                exprResultA.commitInstruction(methodBlock);
                int invokeResultRegister = exprResultA.resultRegister;
            } else {
                throw CompileException("InvokeStmtContext must be InvokeExprContext");
            }
        } else if (FlyScriptParser::IfElseStmtContext *ifElseStmtContext = dynamic_cast<FlyScriptParser::IfElseStmtContext *>(stmtContext)) {
            auto expr = dynamic_cast<FlyScriptParser::ExprContext *>(ifElseStmtContext->children[2]);
            int finalRegister = 0;
            if (FlyScriptParser::OrBooleanExprContext *orBooleanExprContext = dynamic_cast<FlyScriptParser::OrBooleanExprContext *>(expr)) {
                finalRegister = 0;
            } else {
                ExprResult exprResultA = getExprResult(expr, ValueType::T_boolean, methodBlock);
                exprResultA.commitInstruction(methodBlock);
                finalRegister = exprResultA.resultRegister;
            }

            {
                IfInstruction *ifInstruction = new IfInstruction(finalRegister, -1);
                GotoInstruction *gotoInstruction = new GotoInstruction(-1);
                methodBlock->addInstruction(ifInstruction);
                methodBlock->addInstruction(gotoInstruction);
                int block1StartAddress = methodBlock->nextCodeAddress();
                ifInstruction->setAddress(block1StartAddress);

                auto *block1 = dynamic_cast<FlyScriptParser::BlockContext *>(ifElseStmtContext->children[4]);
                auto methodBlock1 = methodBlock->newChildBlock();
                parseBlock(block1, methodBlock1);

                for (Instruction *instruction: methodBlock1->getInstructions()) {
                    methodBlock->addInstruction(instruction);
                }
                int block1EndAddress = methodBlock->nextCodeAddress();
                gotoInstruction->setAddress(block1EndAddress);

                delete methodBlock1;
            }

            if (ifElseStmtContext->children.size() > 5) {
                GotoInstruction *gotoBlock2EndInstruction = new GotoInstruction(-1);
                methodBlock->addInstruction(gotoBlock2EndInstruction);
                auto *block2 = dynamic_cast<FlyScriptParser::BlockContext *>(ifElseStmtContext->children[6]);
                auto methodBlock2 = methodBlock->newChildBlock();
                parseBlock(block2, methodBlock2);
                int block2InstructionCount = methodBlock2->getInstructions().size();
                if (block2InstructionCount == 0) {
                    continue;
                }
                for (Instruction *instruction: methodBlock2->getInstructions()) {
                    methodBlock->addInstruction(instruction);
                }
                int block2EndAddress = methodBlock->nextCodeAddress();
                gotoBlock2EndInstruction->setAddress(block2EndAddress);
                delete methodBlock2;
            }

        } else if (FlyScriptParser::WhileStmtContext *whileStmtContext = dynamic_cast<FlyScriptParser::WhileStmtContext *>(stmtContext)) {
            auto expr = dynamic_cast<FlyScriptParser::ExprContext *>(whileStmtContext->children[2]);
            int judgeStartAddress = methodBlock->nextCodeAddress();
            int finalRegister = 0;
            if (FlyScriptParser::OrBooleanExprContext *orBooleanExprContext = dynamic_cast<FlyScriptParser::OrBooleanExprContext *>(expr)) {
                finalRegister = 0;
            } else {
                ExprResult exprResultA = getExprResult(expr, ValueType::T_boolean, methodBlock);
                exprResultA.commitInstruction(methodBlock);
                finalRegister = exprResultA.resultRegister;
            }
            IfInstruction *ifInstruction = new IfInstruction(finalRegister, -1);
            GotoInstruction *gotoInstruction = new GotoInstruction(-1);
            methodBlock->addInstruction(ifInstruction);
            methodBlock->addInstruction(gotoInstruction);

            int blockStartAddress = methodBlock->nextCodeAddress();
            ifInstruction->setAddress(blockStartAddress);

            auto *block = dynamic_cast<FlyScriptParser::BlockContext *>(whileStmtContext->children[4]);
            auto whileBlock = methodBlock->newChildBlock();
            whileBlock->setIsWhileBlock(true);
            parseBlock(block, whileBlock);
            int blockInstructionCount = whileBlock->getInstructions().size();
            if (blockInstructionCount == 0) {
                continue;
            }
            GotoInstruction *gotoBreakInstruction = nullptr;
            if (whileBlock->getBreakCodeAddress() >= 0) {
                //BreakInstruction *breakInstruction= dynamic_cast<BreakInstruction *>(whileBlock->getInstructions()[whileBlock->getBreakCodeAddress()]);
                gotoBreakInstruction = new GotoInstruction(-1);
                whileBlock->replaceInstruction(whileBlock->getBreakCodeAddress(), gotoBreakInstruction);
                whileBlock->setBreakCodeAddress(-1);
            }
            for (Instruction *instruction: whileBlock->getInstructions()) {
                methodBlock->addInstruction(instruction);
            }
            methodBlock->addInstruction(new GotoInstruction(judgeStartAddress));
            int blockEndAddress = methodBlock->nextCodeAddress();
            gotoInstruction->setAddress(blockEndAddress);
            if (gotoBreakInstruction != nullptr) {
                gotoBreakInstruction->setAddress(blockEndAddress);
            }
            delete whileBlock;
        } else if (FlyScriptParser::BreakStmtContext *breakStmtContext = dynamic_cast<FlyScriptParser::BreakStmtContext *>(stmtContext)) {
            methodBlock->addInstruction(new BreakInstruction());
            auto *whileBlock = methodBlock->findWhileBlock();
            int breakAddress = whileBlock->nextCodeAddressForChild() + methodBlock->currentCodeAddressForChild();
            if (whileBlock == nullptr) {
                throw CompileException("break or continue must be in the while block");
            } else {
                whileBlock->setBreakCodeAddress(breakAddress);
            }
        } else if (FlyScriptParser::ReturnStmtContext *returnStmtContext = dynamic_cast<FlyScriptParser::ReturnStmtContext *>(stmtContext)) {
            auto valueExpr = dynamic_cast<FlyScriptParser::ExprContext *>(returnStmtContext->children[1]);
            if (valueExpr) {
                int exprType = methodBlock->state->getExprType(valueExpr);
                ExprResult exprResultA = getExprResult(valueExpr, exprType, methodBlock);
                exprResultA.commitInstruction(methodBlock);
                int reg = exprResultA.resultRegister;
                methodBlock->addInstruction(new ReturnInstruction(reg, exprType == ValueType::T_void));
            } else {
                methodBlock->addInstruction(new ReturnInstruction());
            }
        }
    }
}

ExprResult
Ast2IrConvertor::getExprResult(FlyScriptParser::ExprContext *exprContext, int type, MethodBlock *methodBlock) {
    ExprResult exprResult = ExprResult();
    if (FlyScriptParser::IdentifierExprContext *identifierExprContext = dynamic_cast<FlyScriptParser::IdentifierExprContext *>(exprContext)) {
        string variableName = identifierExprContext->children[0]->getText();
        if (methodBlock->state->isFieldVariable(variableName)) {
            int getFieldRegister = methodBlock->state->newRegister();
            exprResult.addInstruction(new GetFieldInstruction(getFieldRegister, variableName));
            exprResult.setResultRegister(getFieldRegister);
            return exprResult;
        } else {
            int variableRegister = methodBlock->state->getRegister(variableName);
            if (!variableRegister) {
                throw NonRegisterException(variableName.data());
            }
            exprResult.setResultRegister(variableRegister);
            return exprResult;
        }
    } else if (FlyScriptParser::PlusSubExprContext *plusSubExprContext = dynamic_cast<FlyScriptParser::PlusSubExprContext *>(exprContext)) {
        auto expr1 = dynamic_cast<FlyScriptParser::ExprContext *>(plusSubExprContext->children[0]);
        auto symbol = dynamic_cast<TerminalNodeImpl *>(plusSubExprContext->children[1])->getText();
        auto expr2 = dynamic_cast<FlyScriptParser::ExprContext *>(plusSubExprContext->children[2]);
        if (strcmp(symbol.data(), "+") == 0) {
            auto type1 = methodBlock->state->getExprType(expr1);
            auto type2 = methodBlock->state->getExprType(expr2);
            ExprResult exprResult1 = getExprResult(expr1, type1, methodBlock);
            exprResult1.commitInstruction(exprResult);
            ExprResult exprResult2 = getExprResult(expr2, type2, methodBlock);
            exprResult2.commitInstruction(exprResult);
            auto register1 = exprResult1.resultRegister;
            auto register2 = exprResult2.resultRegister;
            exprResult.addInstruction(new PlusInstruction(register1, register2));
            int resultRegister = methodBlock->state->newRegister();
            exprResult.addInstruction(new MoveResultObjectInstruction(resultRegister));
            exprResult.setResultRegister(resultRegister);
            return exprResult;
        } else if (strcmp(symbol.data(), "-") == 0) {
            if (methodBlock->state->plusSubTypeInference->isStringAndString(expr1, expr2)) {
                throw RuntimeException("Strings cannot be subtracted");
            }
            if (methodBlock->state->plusSubTypeInference->isIntAndString(expr1, expr2)) {
                throw RuntimeException("Strings and numbers cannot be subtracted");
            }
            if (methodBlock->state->plusSubTypeInference->isContainsString(expr1, expr2)) {
                throw RuntimeException("Strings cannot be in sub instruction");
            }
            auto type1 = methodBlock->state->getExprType(expr1);
            auto type2 = methodBlock->state->getExprType(expr2);
            ExprResult exprResult1 = getExprResult(expr1, type1, methodBlock);
            exprResult1.commitInstruction(exprResult);
            ExprResult exprResult2 = getExprResult(expr2, type2, methodBlock);
            exprResult2.commitInstruction(exprResult);
            auto register1 = exprResult1.resultRegister;
            auto register2 = exprResult2.resultRegister;
            exprResult.addInstruction(new SubInstruction(register1, register2));
            int resultRegister = methodBlock->state->newRegister();
            exprResult.addInstruction(new MoveResultObjectInstruction(resultRegister));
            exprResult.setResultRegister(resultRegister);
            return exprResult;
        }
    } else if (FlyScriptParser::BooleanExprContext *booleanExprContext = dynamic_cast<FlyScriptParser::BooleanExprContext *>(exprContext)) {
        auto expr1 = dynamic_cast<FlyScriptParser::ExprContext *>(booleanExprContext->children[0]);
        auto symbol = dynamic_cast<FlyScriptParser::JudgeSymbolContext *>(booleanExprContext->children[1])->getText();
        auto expr2 = dynamic_cast<FlyScriptParser::ExprContext *>(booleanExprContext->children[2]);
        auto type1 = methodBlock->state->getExprType(expr1);
        auto type2 = methodBlock->state->getExprType(expr2);
        ExprResult exprResult1 = getExprResult(expr1, type1, methodBlock);
        exprResult1.commitInstruction(exprResult);
        ExprResult exprResult2 = getExprResult(expr2, type2, methodBlock);
        exprResult2.commitInstruction(exprResult);
        auto register1 = exprResult1.resultRegister;
        auto register2 = exprResult2.resultRegister;
        exprResult.addInstruction(
                new BoolInstruction(register1, BoolInstruction::getSymbolByName(symbol), register2));
        int resultRegister = methodBlock->state->newRegister();
        exprResult.addInstruction(new MoveResultObjectInstruction(resultRegister));
        exprResult.setResultRegister(resultRegister);
        return exprResult;
    } else if (FlyScriptParser::InvokeExprContext *invokeExprContext = dynamic_cast<FlyScriptParser::InvokeExprContext *>(exprContext)) {
        string methodName = dynamic_cast<TerminalNodeImpl *>(invokeExprContext->children[0])->getText();
        int returnType = typeInClassRemember->getMethodReturnType(methodName);
        if (!returnType) {
            returnType = ValueType::T_void;
        }
        auto exprListContext = dynamic_cast<FlyScriptParser::ExprListContext *>(invokeExprContext->children[2]);
        vector<int> paramRegList = vector<int>();
        if (exprListContext) {
            for (int i = 0; i < exprListContext->children.size(); i++) {
                if (FlyScriptParser::ExprContext *childExpr = dynamic_cast<FlyScriptParser::ExprContext *>(exprListContext->children[i])) {
                    int exprType = methodBlock->state->getExprType(childExpr);
                    ExprResult exprResult1 = getExprResult(childExpr, exprType, methodBlock);
                    exprResult1.commitInstruction(exprResult);
                    int reg = exprResult1.resultRegister;
                    paramRegList.push_back(reg);
                } else if (TerminalNodeImpl *splitSymbol = dynamic_cast<TerminalNodeImpl *>(exprListContext->children[i])) {
                    string symbol = splitSymbol->getText();
                    if (strcmp(symbol.data(), ",") != 0) {
                        throw CompileException("splitSymbol must be ','");
                    }
                } else {
                    throw CompileException("childExpr must be ExprContext");
                }
            }
        }
        exprResult.addInstruction(new InvokeInstruction(methodName, paramRegList));
        if (returnType != ValueType::T_void) {
            int invokeResultRegister = methodBlock->state->newRegister();
            exprResult.addInstruction(new MoveResultObjectInstruction(invokeResultRegister));
            exprResult.setResultRegister(invokeResultRegister);
            return exprResult;
        }
        exprResult.setResultRegister(-1);
        return exprResult;
    } else if (FlyScriptParser::BooleanTrueExprContext *booleanTrueExprContext = dynamic_cast<FlyScriptParser::BooleanTrueExprContext *>(exprContext)) {
        int registerA = methodBlock->state->newRegister();
        exprResult.addInstruction(new ConstBooleanInstruction(registerA, true));
        exprResult.setResultRegister(registerA);
        return exprResult;
    } else if (FlyScriptParser::BooleanFalseExprContext *booleanFalseExprContext = dynamic_cast<FlyScriptParser::BooleanFalseExprContext *>(exprContext)) {
        int registerA = methodBlock->state->newRegister();
        exprResult.addInstruction(new ConstBooleanInstruction(registerA, true));
        exprResult.setResultRegister(registerA);
        return exprResult;
    } else if (FlyScriptParser::ParensExprContext *parensExprContext = dynamic_cast<FlyScriptParser::ParensExprContext *>(exprContext)) {
        FlyScriptParser::ExprContext *exprInParens = dynamic_cast<FlyScriptParser::ExprContext *>(parensExprContext->children[1]);
        return getExprResult(exprInParens,type,methodBlock);
    }
    switch (type) {
        case ValueType::T_int: {
            if (FlyScriptParser::IntExprContext *intExprContext = dynamic_cast<FlyScriptParser::IntExprContext *>(exprContext)) {
                int registerA = methodBlock->state->newRegister();
                string text = intExprContext->getText();
                exprResult.addInstruction(new ConstIntInstruction(registerA, stoi(text.data())));
                exprResult.setResultRegister(registerA);
                return exprResult;
            }
        }
        case ValueType::T_string: {
            if (FlyScriptParser::StringExprContext *stringExprContext = dynamic_cast<FlyScriptParser::StringExprContext *>(exprContext)) {
                int registerA = methodBlock->state->newRegister();
                string text = stringExprContext->children[1]->getText();
                exprResult.addInstruction(new ConstStringInstruction(registerA, text.data()));
                exprResult.setResultRegister(registerA);
                return exprResult;
            }
        }
    }
    throw CompileException("this exprContext is unsupported");
}

FileClass *Ast2IrConvertor::generateFileClass() {
    FileClass *fileClass = new FileClass();
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

    auto *mainMethodBlock = new MethodBlock(this->typeInClassRemember);
    for (FlyScriptParser::FieldContext *fieldContext: rawFieldList) {
        string typeString = Ast2IrConvertor::typeContextToString(
                dynamic_cast<FlyScriptParser::TypeContext *>(fieldContext->children[0]));
        string fieldName = dynamic_cast<TerminalNodeImpl *>(fieldContext->children[1])->getText().c_str();
        int type = ValueType::getType(typeString);
        typeInClassRemember->putFieldType(fieldName, type);
        fileClass->addField(new IrField(fieldName, type));
    }
    parseStmt(rawStmtList, mainMethodBlock);
    IrMethod *mainMethod = new IrMethod(ValueType::T_void, "main", vector<MethodParameter *>(),
                                        mainMethodBlock->getInstructions());
    delete mainMethodBlock;
    fileClass->addMethod(mainMethod);

    for (FlyScriptParser::FunctionContext *functionContext: rawFunctionList) {
        auto function2IrMethodConvertor = Function2IrMethodConvertor(this, functionContext);
        auto *method = function2IrMethodConvertor.generateIrMethod();
        fileClass->addMethod(method);
    }

    return fileClass;
}

Ast2IrConvertor::~Ast2IrConvertor() {

}

string Ast2IrConvertor::typeContextToString(FlyScriptParser::TypeContext *typeContext) {
    auto typeValue = dynamic_cast<TerminalNodeImpl *>(typeContext->children[0])->symbol->getType();
    return ValueType::getName(typeValue);
}