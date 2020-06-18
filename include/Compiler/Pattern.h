#pragma once
#include <regex>
namespace IKCL {
template <typename T>
struct Pattern {
    Pattern(T t, std::regex r) {
        type = t;
        rep = r;
    }
    T type;
    std::regex rep;
};
}  // namespace IKCL
