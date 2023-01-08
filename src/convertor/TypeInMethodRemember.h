//
// Created by flying on 2023/1/7.
//

#ifndef FLYLANGUAGE_TYPEINMETHODREMEMBER_H
#define FLYLANGUAGE_TYPEINMETHODREMEMBER_H

#include <map>

class TypeInClassRemember;

using namespace std;

class TypeInMethodRemember {

protected:
    map<string, int> variableTypeMap = map<string, int>();
public:
    TypeInClassRemember *typeInClassRemember;

    TypeInMethodRemember(TypeInClassRemember *typeInClassRemember) {
        this->typeInClassRemember = typeInClassRemember;
    }

    ~TypeInMethodRemember() {

    }

    void putVariableType(string variableName, int valueType) {
        variableTypeMap[variableName] = valueType;
    }

    int getVariableType(string variableName) {
        return variableTypeMap[variableName];
    }

};

#endif //FLYLANGUAGE_TYPEINMETHODREMEMBER_H
