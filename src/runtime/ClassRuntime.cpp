//
// Created by flying on 2023/1/8.
//

#include "ClassRuntime.h"
#include "file.h"

ClassRuntime::ClassRuntime(const FileClass &fileClass) : fileClass(fileClass) {

}

any ClassRuntime::getFieldValue(string fieldName) {
    return fieldValueMap[fieldName];
}

void ClassRuntime::setFieldValue(string fieldName, any value) {
    fieldValueMap[fieldName] = value;
}

void ClassRuntime::execute() {

    //IrMethod *mainMethod=NULL;
    for (IrMethod irMethod: fileClass.getMethods()) {
        if (strcmp(irMethod.getName().data(), "main") == 0) {
            //mainMethod=&irMethod;
            MethodExecutor methodExecutor = MethodExecutor(this, &irMethod);
            methodExecutor.execute();
            return;
        }
    }
    throw RuntimeException("cannot find the main method");
}

ClassRuntime::~ClassRuntime() {

}



