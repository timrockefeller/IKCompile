#pragma once
#include <regex>
namespace IKCL {

template <typename T>
class ASTNode {
   public:
    ASTNode() = default;
    ASTNode(T t)
        : type(t) {}
    T type;
};

}  // namespace IKCL
