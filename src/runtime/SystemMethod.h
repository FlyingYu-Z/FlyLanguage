//
// Created by flying on 2023/1/8.
//

#ifndef FLYLANGUAGE_SYSTEMMETHOD_H
#define FLYLANGUAGE_SYSTEMMETHOD_H

#include <map>
#include <any>
#include <fmt/printf.h>
#include <vector>
#include <functional>
#include "ValueCalc.h"
#include "MethodNotFoundException.h"

using namespace std;

class SystemMethod {

protected:
    typedef map<string, std::function<bool(std::vector<any>)>> SystemMethodMap;
    static SystemMethodMap systemMethodMap;

    static SystemMethodMap init_map() {
        SystemMethodMap tmpSystemMethodMap;

        tmpSystemMethodMap["print"] = print_wrapper;
        tmpSystemMethodMap["println"] = println_wrapper;

//        std::map<std::string, std::function<bool(std::vector<void*>)>>  funcMap =
//                {
//                        {"print", print_wrapper}
//                };

        return tmpSystemMethodMap;
    }

public:
    static bool isSystemMethod(string methodName) {
        auto iter = systemMethodMap.find(methodName);
        if (iter != systemMethodMap.end()) {
            return true;
        }
        return false;
    }

    //template <typename... Args>
    static void invokeMethod(string methodName, vector<any> argList) {
        auto iter = systemMethodMap.find(methodName);
        if (iter == systemMethodMap.end()) {
            throw MethodNotFoundException(methodName);
        }
//        std::vector<void*> arg_pointers;
//        (arg_pointers.push_back(reinterpret_cast<void*>(std::addressof(args))),...);
//        iter->second(arg_pointers);

        std::function<bool(std::vector<any>)> func = iter->second;
        func(argList);
    }

public:
    static bool print_wrapper(std::vector<any> args) {
        if (args.size() != 1) {
            return false;
        }
        print(args[0]);
        return true;
    }

    static void print(any value) {
        int type=ValueCalc::ctype2vtype(value.type());
        string printValue=ValueCalc::valueToString(type,value);
        printf(printValue.data());
    }

    static bool println_wrapper(std::vector<any> args) {
        if (args.size() != 1) {
            return false;
        }
        println(args[0]);
        return true;
    }

    static void println(any value) {
        int type=ValueCalc::ctype2vtype(value.type());
        string printValue=ValueCalc::valueToString(type,value);
        printf("%s\n", printValue.data());
    }

};


#endif //FLYLANGUAGE_SYSTEMMETHOD_H
