//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_VALUECOMPARE_H
#define FLYLANGUAGE_VALUECOMPARE_H

#include "BoolInstruction.h"

template< typename T>
class ValueCompare {

protected:
    T value1;
    int symbol;
    T value2;

public:
    ValueCompare(T value1, int symbol, T value2) : value1(value1), symbol(symbol), value2(value2) {

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
            case BoolInstruction::LesserrOrEqual: {
                return compareLesserrOrEqual();
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
    virtual bool compareLesserrOrEqual(){}
    virtual bool compareLesser(){}

    virtual ~ValueCompare() {

    }

};

#endif //FLYLANGUAGE_VALUECOMPARE_H
