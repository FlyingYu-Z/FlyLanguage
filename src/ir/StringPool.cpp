//
// Created by flying on 2023/1/7.
//

#include "StringPool.h"


StringPool::StringPool() {
    vector<int> valueTypeList = ValueType::getValueTypeList();
    for(int i=0;i<valueTypeList.size();i++){
        addString(ValueType::getName(valueTypeList[i]));
    }
}

void StringPool::addString(string_view str) {

}

int StringPool::indexOf(string_view str) {

}

StringPool::~StringPool() {

}