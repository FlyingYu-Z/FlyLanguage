//
// Created by flying on 2023/1/9.
//

#ifndef FLYLANGUAGE_FLOATVALUECOMPARATOR_H
#define FLYLANGUAGE_FLOATVALUECOMPARATOR_H

#include "ValueComparator.h"

class FloatValueComparator : public ValueComparator<float> {

public:
    FloatValueComparator(float value1, int symbol, float value2) : ValueComparator(value1, symbol, value2) {

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

    ~FloatValueComparator() override {

    }

};

#endif //FLYLANGUAGE_FLOATVALUECOMPARATOR_H
