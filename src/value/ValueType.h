#pragma once
//
// Created by flying on 2023/1/5.
//

#ifndef FLYLANGUAGE_VALUETYPE_H
#define FLYLANGUAGE_VALUETYPE_H


#include "FlyScriptLexer.h"
#include "FlyScriptParser.h"

#include <map>

using namespace std;
using namespace beingyi;

//map<int, string_view> valueTypeMap = map<int, string_view>();

//#define VALUE_TYPE \
//X(T_void, "void", FlyScriptLexer::Type_void) \
//X(T_string, "string", FlyScriptLexer::Type_string) \
//X(T_float, "float", FlyScriptLexer::Type_float) \
//X(T_int, "int", FlyScriptLexer::Type_int) \
//X(T_boolean, "boolean", FlyScriptLexer::Type_boolean) \

#define VALUE_TYPE \
X(T_void, "void", 0x001) \
X(T_string, "string", 0x002) \
X(T_float, "float", 0x003) \
X(T_int, "int", 0x004) \
X(T_boolean, "boolean", 0x005) \


class ValueType {
public:
    enum : uint8_t {
#define X(enumName, name, value) enumName = value,
        VALUE_TYPE
#undef X
    };

protected:
    typedef std::map<std::string_view, int> NameMap;
    static NameMap nameMap;
    static NameMap init_map() {
        NameMap tmpNameMap;
#define X(enumName, name, value) tmpNameMap[name]=value;
        VALUE_TYPE
#undef X
        return tmpNameMap;
    }
public:
    static vector<int> getValueTypeList() {
        vector<int> typeList = vector<int>();
#define X(enumName, name, value) typeList.push_back(enumName);
        VALUE_TYPE
#undef X
        return typeList;
    }

    static int getType(string_view name){
        return nameMap[name];
    }

    static const char *getName(int value) {
        switch (value) {
#define X(enumName, name, value) case value: return name;
            VALUE_TYPE
#undef X
        }
        throw std::runtime_error("unknown value");
    }

};


#endif //FLYLANGUAGE_VALUETYPE_H
