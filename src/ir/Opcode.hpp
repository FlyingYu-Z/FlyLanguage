//
// Created by flying on 2023/1/6.
//

#ifndef FLYLANGUAGE_OPCODE_HPP
#define FLYLANGUAGE_OPCODE_HPP

#include <map>

using namespace std;

#define OPCODE \
X_OPCODE(Nop, "nop", 0x000) \
X_OPCODE(ConstInt, "const-int", 0x001) \
X_OPCODE(ConstString, "const-string", 0x002) \


enum Opcode {

#define X_OPCODE(enumName, name, value) enumName = value,
    OPCODE
#undef X_OPCODE

//public:
//    class Value {
//    public:
//#define X_OPCODE(enumName, name, value) static const uint8_t enumName = value;
//        OPCODE
//#undef X_OPCODE
//    };


};

static const char *getOpcodeName(int value) {
    switch (value) {
#define X_OPCODE(enumName, name, value) case Opcode::enumName: return name;
        OPCODE
#undef X_OPCODE
    }
    throw std::runtime_error("unknown opcode value");
}


#endif //FLYLANGUAGE_OPCODE_HPP
