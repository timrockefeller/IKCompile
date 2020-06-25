#pragma once
#include <ostream>
#include <string>
#include <type_traits>
namespace IKCL {
template <typename T,typename = std::enable_if< std::is_enum<T>::value >>
class Token {
   private:
    /* data */
   public:
    T token;
    size_t length;
    std::string strval;
    int intval = 0;
    float floatval = 0;
    friend std::ostream& operator<<(std::ostream& os, const Token& to) {
        return os << to.strval;
    }
};
}  // namespace IKCL
