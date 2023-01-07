#pragma once
//
// Created by flying on 2023/1/5.
//

#ifndef FLYLANGUAGE_VALUETYPE_HPP
#define FLYLANGUAGE_VALUETYPE_HPP


#include "FlyScriptLexer.h"
#include "FlyScriptParser.h"

#include <map>

using namespace std;
using namespace beingyi;

//map<int, string_view> valueTypeMap = map<int, string_view>();

#define VALUE_TYPE \
X(T_void, "void", FlyScriptLexer::Type_void) \
X(T_string, "string", FlyScriptLexer::Type_string) \
X(T_float, "float", FlyScriptLexer::Type_float) \
X(T_int, "int", FlyScriptLexer::Type_int) \
X(T_boolean, "boolean", FlyScriptLexer::Type_boolean) \


class ValueType {
public:
    enum : uint8_t {
#define X(enumName, name, value) enumName = value,
        VALUE_TYPE
#undef X
    };

    static vector<int> getValueTypeList() {
        vector<int> typeList = vector<int>();
#define X(enumName, name, value) typeList.push_back(enumName);
        VALUE_TYPE
#undef X
        return typeList;
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


#endif //FLYLANGUAGE_VALUETYPE_HPP
