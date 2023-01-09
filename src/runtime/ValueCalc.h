//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_VALUECALC_H
#define FLYLANGUAGE_VALUECALC_H

#include <sstream>
#include <string>
#include <any>
#include "ValueType.h"
#include "RuntimeException.h"


using namespace std;

class ValueCalc {


public:
    static int ctype2vtype(const type_info& ctype){
        if(ctype== typeid(int)){
            return ValueType::T_int;
        } else if(ctype== typeid(float)){
            return ValueType::T_float;
        }else if(ctype== typeid(string)){
            return ValueType::T_string;
        }else if(ctype== typeid(bool)){
            return ValueType::T_boolean;
        }
        throw RuntimeException("unknown ctype");
    }

    static int getHighestTypeForBoolInstruction(int type1, int type2) {
        if (isSameType(type1,type2,ValueType::T_int)) {
            return ValueType::T_int;
        }
        if (isSameType(type1,type2,ValueType::T_float)) {
            return ValueType::T_float;
        }
        if(containsTowType(type1,type2,ValueType::T_int,ValueType::T_float)){
            return ValueType::T_float;
        }
        throw RuntimeException("unsupported type merger");
    }

    static int getHighestTypeForPlusInstruction(int type1, int type2) {
        if (isSameType(type1,type2,ValueType::T_int)) {
            return ValueType::T_int;
        }
        if (isSameType(type1,type2,ValueType::T_float)) {
            return ValueType::T_float;
        }
        if (isSameType(type1,type2,ValueType::T_string)) {
            return ValueType::T_string;
        }
        if(containsTowType(type1,type2,ValueType::T_int,ValueType::T_float)){
            return ValueType::T_float;
        }
        if(containsType(type1,type2,ValueType::T_string)){
            return ValueType::T_string;
        }
        throw RuntimeException("unsupported type merger");
    }

    static string valueToString(int type,any value){
        switch (type) {
            case ValueType::T_int:{
                return std::to_string(any_cast<int>(value));
            }
            case ValueType::T_float:{
                return std::to_string(any_cast<float>(value));
            }
            case ValueType::T_string:{
                return any_cast<string>(value);
            }
            default:
                const void * address = any_cast<void *>(value);
                std::stringstream ss;
                ss << address;
                std::string name = ss.str();
                return name;
        }
    }

    inline static bool isSameType(int type1,int type2) {
        return type1 == type2;
    }

    inline static bool isSameType(int type1,int type2,int valueType) {
        return type1 == valueType && type2 == valueType;
    }

    inline static bool containsType(int type1,int type2, int valueType) {
        return type1 == valueType || type2 == valueType;
    }

    inline static bool containsTowType(int type1,int type2, int valueType1,int valueType2) {
        return (type1 == valueType1 && type2 == valueType2) || (type1 == valueType2 && type2 == valueType1);
    }


};


#endif //FLYLANGUAGE_VALUECALC_H
