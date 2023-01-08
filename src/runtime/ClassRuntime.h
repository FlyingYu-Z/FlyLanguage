//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_CLASSRUNTIME_H
#define FLYLANGUAGE_CLASSRUNTIME_H

#include "MethodExecutor.h"

using namespace std;

class ClassRuntime {
private:
    map<string, any> fieldValueMap = map<string, any>();

protected:
    FileClass fileClass;

public:
    ClassRuntime(const FileClass &fileClass);

    any getFieldValue(string fieldName);

    void setFieldValue(string fieldName, any value);

    void execute();

    ~ClassRuntime();

};


#endif //FLYLANGUAGE_CLASSRUNTIME_H
