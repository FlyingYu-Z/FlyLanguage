//
// Created by flying on 2023/1/9.
//

#ifndef FLYLANGUAGE_METHODNOTFOUNDEXCEPTION_H
#define FLYLANGUAGE_METHODNOTFOUNDEXCEPTION_H

#include <iostream>
#include <exception>
#include <string>
#include <fmt/printf.h>

using namespace std;

class MethodNotFoundException : public exception {
public:
    MethodNotFoundException(string methodName) : message(fmt::sprintf("method '%s' not found",methodName.data())) {}
    ~MethodNotFoundException() throw () {
    }

    virtual const char* what() const throw () {
        return message.c_str();
    }

private:
    string message;
};


#endif //FLYLANGUAGE_METHODNOTFOUNDEXCEPTION_H
