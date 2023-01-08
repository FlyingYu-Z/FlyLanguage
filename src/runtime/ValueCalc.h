//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_VALUECALC_H
#define FLYLANGUAGE_VALUECALC_H

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
        }else if(ctype== typeid(bool)){
            return ValueType::T_boolean;
        }
        throw RuntimeException("unknown ctype");
    }

    static int getHighestType(int type1, int type2) {
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
