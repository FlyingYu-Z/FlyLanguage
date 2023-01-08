//
// Created by flying on 2023/1/7.
//

#ifndef FLYLANGUAGE_STRINGPOOL_H
#define FLYLANGUAGE_STRINGPOOL_H

#include <string_view>
#include <vector>
#include "ValueType.h"

using namespace std;

class StringPool {

protected:
    vector<string> strings = vector<string>();

public:
    StringPool();

    void addString(string str);
    int indexOf(string str);

    ~StringPool();

};


#endif //FLYLANGUAGE_STRINGPOOL_H
