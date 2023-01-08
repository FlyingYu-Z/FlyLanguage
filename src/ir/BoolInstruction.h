//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_BOOLINSTRUCTION_H
#define FLYLANGUAGE_BOOLINSTRUCTION_H

#include "Instruction.h"


#define SYMBOL \
X_Symbol(JudgeEqual, "==", 0x000) \
X_Symbol(NotEqual, "!=", 0x001) \
X_Symbol(GreaterOrEqual, ">=", 0x002) \
X_Symbol(Greater, ">", 0x003) \
X_Symbol(LesserrOrEqual, "<=", 0x004) \
X_Symbol(Lesser, "<", 0x005) \


class BoolInstruction : public Instruction {

public:
    enum Symbol: uint8_t {
#define X_Symbol(enumName, name, value) enumName = value,
        SYMBOL
#undef X_Symbol

    };

protected:
    int registerA;
    int symbol;
    int registerB;

    typedef std::map<std::string, int> SymbolMap;
    static SymbolMap symbolMap;
    static SymbolMap init_map() {
        SymbolMap tmpSymbolMap;
#define X_Symbol(enumName, name, value) tmpSymbolMap[name] = enumName;
        SYMBOL
#undef X_Symbol
        return tmpSymbolMap;
    }
public:
    static int getSymbolByName(string name){
        return symbolMap[name];
    }
    static const char *getSymbolName(int value) {
        switch (value) {
#define X_Symbol(enumName, name, value) case Symbol::enumName: return name;
            SYMBOL
#undef X_Symbol
        }
        throw std::runtime_error("unknown opcode value");
    }

public:
    BoolInstruction(int registerA, int symbol, int registerB) : registerA(registerA), symbol(symbol),
                                                                                 registerB(registerB) {

    }

    virtual ~BoolInstruction() {
    }

    int getRegisterA() const {
        return registerA;
    }

    int getSymbol() const {
        return symbol;
    }

    int getRegisterB() const {
        return registerB;
    }

    int getOpcode() override {
        return Opcode::Bool;
    }


};

#endif //FLYLANGUAGE_BOOLINSTRUCTION_H
