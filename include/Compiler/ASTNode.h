#pragma once

namespace IKCL {

template <typename T>
struct ASTNode {
    ASTNode(T tokentype, std::regex regexpattern) {
        type = tokentype;
        rep = regexpattern;
    }
    T type;
    std::regex rep;
};

}  // namespace IKCL
