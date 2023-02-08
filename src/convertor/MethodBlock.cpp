//
// Created by flying on 2023/1/7.
//

#include "MethodBlock.h"
#include "Ast2IrConvertor.h"


MethodBlock::MethodBlock(TypeInClassRemember *typeInClassRemember) {
    this->typeInClassRemember = typeInClassRemember;
    BlockState *state = new BlockState();
    state->typeInMethodRemember = new TypeInMethodRemember(this->typeInClassRemember);
    state->plusSubTypeInference = new PlusSubTypeInference(this);
    this->state = state;
}

MethodBlock *MethodBlock::newChildBlock() {
    auto *methodBlock = new MethodBlock(this->typeInClassRemember);
    methodBlock->parentMethodBlock = this;
    methodBlock->isChild = true;
    BlockState *state = new BlockState();
    state->setParent(this->state);
    state->typeInMethodRemember = this->state->typeInMethodRemember;
    state->plusSubTypeInference = this->state->plusSubTypeInference;
    methodBlock->state = state;
    return methodBlock;
}

int MethodBlock::addInstruction(Instruction *instruction) {
    instructions.push_back(instruction);
    return currentCodeAddress();
}

void MethodBlock::replaceInstruction(int index, Instruction *instruction) {
    Instruction *instructionOrigin = dynamic_cast<Instruction *>(instructions[index]);
    instructions[index] = instruction;
    delete instructionOrigin;
}

vector<Instruction *> MethodBlock::getInstructions() {
    return instructions;
}

int MethodBlock::previousCodeAddress() {
    return currentCodeAddress() - 1;
}

int MethodBlock::currentCodeAddress() {
    int address = 0;
    MethodBlock *parent = this;
    while (parent != nullptr) {
        address += parent->instructions.size();
        parent = parent->parentMethodBlock;
    }
    return address - 1;
}

int MethodBlock::currentCodeAddressForChild() {
    return instructions.size() - 1;
}

int MethodBlock::nextCodeAddress() {
    return currentCodeAddress() + 1;
}

int MethodBlock::nextCodeAddressForChild() {
    return currentCodeAddressForChild() + 1;
}

int MethodBlock::getBreakCodeAddress() const {
    return breakCodeAddress;
}

void MethodBlock::setIsWhileBlock(bool isWhileBlock) {
    this->isWhileBlock = isWhileBlock;
}

MethodBlock *MethodBlock::findWhileBlock() {
    MethodBlock *parent = this;
    while (parent != nullptr) {
        if (parent->isWhileBlock) {
            return parent;
        }
        parent = parent->parentMethodBlock;
    }
    return nullptr;
}

void MethodBlock::setBreakCodeAddress(int breakCodeAddress) {
    MethodBlock::breakCodeAddress = breakCodeAddress;
}


MethodBlock::~MethodBlock() {
    instructions.clear();
}


