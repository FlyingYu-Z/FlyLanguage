//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_INTVALUECOMPARATOR_H
#define FLYLANGUAGE_INTVALUECOMPARATOR_H

#include "ValueComparator.h"

class IntValueComparator : public ValueComparator<int> {

public:
    IntValueComparator(int value1, int symbol, int value2) : ValueComparator(value1, symbol, value2) {

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

    bool compareLesserOrEqual() override {
        return value1 <= value2;
    }

    bool compareLesser() override {
        return value1 < value2;
    }

    ~IntValueComparator() override {

    }

};

#endif //FLYLANGUAGE_INTVALUECOMPARATOR_H
