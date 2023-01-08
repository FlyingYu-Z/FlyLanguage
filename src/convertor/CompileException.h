//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_COMPILEEXCEPTION_H
#define FLYLANGUAGE_COMPILEEXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class CompileException : public exception {
public:
    CompileException(string msg) : message(msg) {}
    ~CompileException() throw () {
    }

    virtual const char* what() const throw () {
        return message.c_str();
    }

private:
    string message;
};

#endif //FLYLANGUAGE_COMPILEEXCEPTION_H
