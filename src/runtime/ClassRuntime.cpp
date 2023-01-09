//
// Created by flying on 2023/1/8.
//

#include "ClassRuntime.h"
#include "file.h"

ClassRuntime::ClassRuntime(FileClass *fileClass) : fileClass(fileClass) {

}

Value ClassRuntime::getFieldValue(string fieldName) {
    return fieldValueMap.at(fieldName);
}

void ClassRuntime::setFieldValue(string fieldName, Value value) {
    auto iter = fieldValueMap.find(fieldName);
    if (iter != fieldValueMap.end()) {
        fieldValueMap.erase(iter);//delete if exists
    }
    fieldValueMap.insert(map<string, Value>::value_type(fieldName, value));
}

MethodExecutor ClassRuntime::getMethodExecutor(string methodName) {
    //IrMethod *mainMethod=NULL;
    for (IrMethod *irMethod: fileClass->getMethods()) {
        if (strcmp(irMethod->getName().data(), methodName.data()) == 0) {
            //mainMethod=&irMethod;
            MethodExecutor methodExecutor = MethodExecutor(this, irMethod);
            return methodExecutor;
        }
    }
    throw RuntimeException(fmt::sprintf("cannot find the method ->%s", methodName.data()));
}

void ClassRuntime::execute() {
    MethodExecutor methodExecutor = getMethodExecutor("main");
    methodExecutor.execute();
}

ClassRuntime::~ClassRuntime() {
    delete fileClass;
}

