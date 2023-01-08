//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_SYSTEMMETHOD_H
#define FLYLANGUAGE_SYSTEMMETHOD_H

#include <map>
#include <any>
#include <fmt/printf.h>

using namespace std;

class SystemMethod {

protected:
    typedef map<string, void *> SystemMethodMap;
    static SystemMethodMap systemMethodMap;

    static SystemMethodMap init_map() {
        SystemMethodMap tmpSystemMethodMap;

        tmpSystemMethodMap["print"] = (void *) print;
        tmpSystemMethodMap["println"] = (void *) println;


        return tmpSystemMethodMap;
    }

    static void invokeMethod(){

    }

public:
    static void print(string value) {
        printf(value.data());
    }

    static void println(string value) {
        print(fmt::sprintf("%s\n", value.data()));
    }

};


#endif //FLYLANGUAGE_SYSTEMMETHOD_H
