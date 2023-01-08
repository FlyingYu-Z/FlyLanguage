//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_RUNTIMEEXCEPTION_H
#define FLYLANGUAGE_RUNTIMEEXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class RuntimeException : public exception {
public:
    RuntimeException(string msg) : message(msg) {}
    ~RuntimeException() throw () {
    }

    virtual const char* what() const throw () {
        return message.c_str();
    }

private:
    string message;
};

#endif //FLYLANGUAGE_RUNTIMEEXCEPTION_H
