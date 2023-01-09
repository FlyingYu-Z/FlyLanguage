//
// Created by flying on 2023/1/9.
//

#ifndef FLYLANGUAGE_VALUE_H
#define FLYLANGUAGE_VALUE_H

#include <any>

using namespace std;

class Value {

private:
    int type;
    any value;

public:
    Value(int type, const any &value);

    Value(int type);

    int getType() const;

    void setType(int type);

    const any &getValue() const;

    void setValue(const any &value);

    virtual ~Value();

};


#endif //FLYLANGUAGE_VALUE_H
