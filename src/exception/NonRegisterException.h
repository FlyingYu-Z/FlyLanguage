//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_NONREGISTEREXCEPTION_H
#define FLYLANGUAGE_NONREGISTEREXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class NonRegisterException : public exception {
public:
    NonRegisterException(string variableName) : message(fmt::sprintf("variable '%s' has no register",variableName)) {}
    ~NonRegisterException() throw () {
    }

    virtual const char* what() const throw () {
        return message.c_str();
    }

private:
    string message;
};


#endif //FLYLANGUAGE_NONREGISTEREXCEPTION_H
