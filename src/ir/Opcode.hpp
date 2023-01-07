//
// Created by flying on 2023/1/6.
//

#ifndef FLYLANGUAGE_OPCODE_H
#define FLYLANGUAGE_OPCODE_H

#include <map>

using namespace std;

#define OPCODE \
X_OPCODE(Nop, "nop", 0x000) \
X_OPCODE(ConstInt, "const-int", 0x001) \
X_OPCODE(ConstString, "const-string", 0x002) \


class Opcode {

public:
    enum : uint8_t {
#define X_OPCODE(enumName, name, value) enumName = value,
        OPCODE
#undef X_OPCODE
    };


public:
    Opcode() {
    }

    ~Opcode() {

    }

    static const char *getName(int value) {
        switch (value) {
#define X_OPCODE(enumName, name, value) case value: return name;
            OPCODE
#undef X_OPCODE
        }
        throw std::runtime_error("unknown opcode value");
    }

public:
    static class Value {
#define X_OPCODE(enumName, name, value) public: static const int enumName = value;
        OPCODE
#undef X_OPCODE
    };


};


#endif //FLYLANGUAGE_OPCODE_H
