#pragma once
#include <regex>
namespace IKCL {

/**
 * Build with enum type of tokens
 * */    
template <typename T>
struct Pattern {
    Pattern(T tokentype, std::regex regexpattern) {
        type = tokentype;
        rep = regexpattern;
    }
    T type;
    std::regex rep;
};
}  // namespace IKCL
