#pragma once
#include <ostream>
#include <string>

namespace IKCL {
template <typename T>
class Token {
   private:
    /* data */
   public:
    T token;
    size_t length;
    std::string strval;
    int intval;
    float floatval;
    friend std::ostream& operator<<(std::ostream&, const Token&);
};
}  // namespace IKCL
