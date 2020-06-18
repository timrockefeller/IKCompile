#pragma once
#include <ostream>
#include <string>

namespace IKCL {
class Token {
   private:
    /* data */
   public:
    Token(/* args */);
    ~Token();
    std::string token;
    int length;
    std::string strval;
    int intval;
    float floatval;
    friend std::ostream& operator<<(std::ostream&, const Token&);
};
}  // namespace IKCL
