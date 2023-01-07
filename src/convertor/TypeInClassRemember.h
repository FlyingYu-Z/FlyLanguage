//
// Created by flying on 2023/1/5.
//

#ifndef FLYLANGUAGE_TYPEINCLASSREMEMBER_H
#define FLYLANGUAGE_TYPEINCLASSREMEMBER_H

#include <map>

using namespace std;

class TypeInClassRemember {

public:
    map<string_view, int> fieldTypeMap = map<string_view, int>();
    map<string_view, int> methodReturnTypeMap = map<string_view, int>();

    TypeInClassRemember() {

    }

    ~TypeInClassRemember() {

    }

    void putFieldType(string_view fieldName, int valueType) {
        fieldTypeMap[fieldName] = valueType;
    }

    int getFieldType(string_view fieldName) {
        return fieldTypeMap[fieldName];
    }

    void putMethodReturnType(string_view methodName, int valueType) {
        methodReturnTypeMap[methodName] = valueType;
    }

    int getMethodReturnType(string_view methodName) {
        return methodReturnTypeMap[methodName];
    }


};


#endif //FLYLANGUAGE_TYPEINCLASSREMEMBER_H
