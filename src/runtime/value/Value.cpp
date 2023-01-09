//
// Created by flying on 2023/1/9.
//

#include "Value.h"

Value::Value(int type, const any &value) : type(type), value(value) {


}

Value::Value(int type) : type(type) {

}

int Value::getType() const {
    return type;
}

void Value::setType(int type) {
    Value::type = type;
}

const any &Value::getValue() const {
    return value;
}

void Value::setValue(const any &value) {
    Value::value = value;
}


Value::~Value() {

}

