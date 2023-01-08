//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_INTVALUECOMPARE_H
#define FLYLANGUAGE_INTVALUECOMPARE_H

#include "ValueCompare.h"

class IntValueCompare : public ValueCompare<int> {

public:
    IntValueCompare(int value1, int symbol, int value2) : ValueCompare(value1, symbol, value2) {

    }

    bool compareJudgeEqual() override {
        return value1 == value2;
    }

    bool compareNotEqual() override {
        return value1 != value2;
    }

    bool compareGreaterOrEqual() override {
        return value1 >= value2;
    }

    bool compareGreater() override {
        return value1 > value2;
    }

    bool compareLesserrOrEqual() override {
        return value1 <= value2;
    }

    bool compareLesser() override {
        return value1 < value2;
    }

    ~IntValueCompare() override {

    }

};

#endif //FLYLANGUAGE_INTVALUECOMPARE_H
