//
// Created by flying on 2023/1/7.
//

#ifndef FLYLANGUAGE_STRING_UTILS_H
#define FLYLANGUAGE_STRING_UTILS_H

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

template<typename ... Args>
std::string string_format(const std::string &format, Args ... args) {
    int size_s = std::snprintf(nullptr, 0, format.data(), args ...) + 1; // Extra space for '\0'
    if (size_s <= 0) { throw std::runtime_error("Error during formatting."); }
    auto size = static_cast<size_t>( size_s );
    std::unique_ptr<char[]> buf(new char[size]);
    std::snprintf(buf.get(), size, format.data(), args ...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

uint64_t numlen(uint64_t num)
{
    uint64_t len = 0;        // 初始长度为0
    for(; num > 0; ++len)    // 判断num是否大于0，否则长度+1
        num /= 10;	         // 使用除法进行运算，直到num小于1
    return len;              // 返回长度的值
}


#endif //FLYLANGUAGE_STRING_UTILS_H
