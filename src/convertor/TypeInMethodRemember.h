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
    map<string_view, int> variableTypeMap = map<string_view, int>();
    TypeInClassRemember *typeInClassRemember;
public:

    TypeInMethodRemember(TypeInClassRemember *typeInClassRemember) {
        this->typeInClassRemember = typeInClassRemember;
    }

    ~TypeInMethodRemember() {

    }

    void putVariableType(string_view variableName, int valueType) {
        variableTypeMap[variableName] = valueType;
    }

    int getVariableType(string_view variableName) {
        return variableTypeMap[variableName];
    }

};

#endif //FLYLANGUAGE_TYPEINMETHODREMEMBER_H
