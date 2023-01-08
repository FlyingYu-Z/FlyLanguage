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
X_OPCODE(ConstFloat,"const-float", 0x003)\
X_OPCODE(ConstParam,"const-param", 0x004)\
X_OPCODE(MoveResultObject,"move-result-object", 0x005)\
X_OPCODE(Move,"move", 0x006)\
X_OPCODE(Invoke,"invoke", 0x007)\
X_OPCODE(Plus,"plus", 0x008)\
X_OPCODE(Sub,"sub", 0x009)\
X_OPCODE(Bool,"bool", 0x010)\
X_OPCODE(If,"if", 0x011)\
X_OPCODE(IfNot,"if-not", 0x012)\
X_OPCODE(Goto,"goto", 0x013)\
X_OPCODE(SetField,"set-field", 0x014)\
X_OPCODE(GetField,"get-field", 0x015)\

class Opcode {
public:
    typedef std::map<std::string_view, int> OpMap;
    static OpMap opMap_;
public:
    typedef enum : uint8_t {

#define X_OPCODE(enumName, name, value) enumName = value,
        OPCODE
#undef X_OPCODE

    };

private:
    static OpMap init_map() {
        OpMap opMap;
#define X_OPCODE(enumName, name, value) opMap[name] = enumName;
        OPCODE
#undef X_OPCODE
        return opMap;
    }

public:

    static int getOpcode(string_view name) {
        return opMap_[name];
    }
    static const char *getOpcodeName(int value) {
        switch (value) {
#define X_OPCODE(enumName, name, value) case Opcode::enumName: return name;
            OPCODE
#undef X_OPCODE
        }
        throw std::runtime_error("unknown opcode value");
    }

};


#endif //FLYLANGUAGE_OPCODE_H
