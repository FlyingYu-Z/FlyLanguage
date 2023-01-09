//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_VALUECOMPARATOR_H
#define FLYLANGUAGE_VALUECOMPARATOR_H

#include "BoolInstruction.h"

template< typename T>
class ValueComparator {

protected:
    T value1;
    int symbol;
    T value2;

public:
    ValueComparator(T value1, int symbol, T value2) : value1(value1), symbol(symbol), value2(value2) {

    }

    bool compare(){
        switch (symbol) {
            case BoolInstruction::JudgeEqual: {
                return compareJudgeEqual();
            }
            case BoolInstruction::NotEqual: {
                return compareNotEqual();
            }
            case BoolInstruction::GreaterOrEqual: {
                return compareGreaterOrEqual();
            }
            case BoolInstruction::Greater: {
                return compareGreater();
            }
            case BoolInstruction::LesserOrEqual: {
                return compareLesserOrEqual();
            }
            case BoolInstruction::Lesser: {
                return compareLesser();
            }
            default:
                return false;
        }
    }

    virtual bool compareJudgeEqual(){}
    virtual bool compareNotEqual(){}
    virtual bool compareGreaterOrEqual(){}
    virtual bool compareGreater(){}
    virtual bool compareLesserOrEqual(){}
    virtual bool compareLesser(){}

    virtual ~ValueComparator() {

    }

};

#endif //FLYLANGUAGE_VALUECOMPARATOR_H
