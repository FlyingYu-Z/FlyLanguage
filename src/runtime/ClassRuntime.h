//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_CLASSRUNTIME_H
#define FLYLANGUAGE_CLASSRUNTIME_H

#include "MethodExecutor.h"

using namespace std;

class ClassRuntime {
private:
    map<string, Value> fieldValueMap = map<string, Value>();

protected:
    FileClass *fileClass;

public:
    ClassRuntime(FileClass *fileClass);

    Value getFieldValue(string fieldName);

    void setFieldValue(string fieldName, Value value);

    MethodExecutor getMethodExecutor(string methodName);

    void execute();

    ~ClassRuntime();

};


#endif //FLYLANGUAGE_CLASSRUNTIME_H
