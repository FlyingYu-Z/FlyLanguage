//
// Created by flying on 2023/1/5.
//

#ifndef FLYLANGUAGE_TYPEINCLASSREMEMBER_H
#define FLYLANGUAGE_TYPEINCLASSREMEMBER_H

#include <map>

using namespace std;

class TypeInClassRemember {

public:
    map<string, int> fieldTypeMap = map<string, int>();
    map<string, int> methodReturnTypeMap = map<string, int>();

    TypeInClassRemember() {

    }

    ~TypeInClassRemember() {

    }

    void putFieldType(string fieldName, int valueType) {
        fieldTypeMap[fieldName] = valueType;
    }

    int getFieldType(string fieldName) {
        return fieldTypeMap[fieldName];
    }

    void putMethodReturnType(string methodName, int valueType) {
        methodReturnTypeMap[methodName] = valueType;
    }

    int getMethodReturnType(string methodName) {
        return methodReturnTypeMap[methodName];
    }


};


#endif //FLYLANGUAGE_TYPEINCLASSREMEMBER_H
