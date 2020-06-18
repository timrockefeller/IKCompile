#pragma once

#include <Compiler/ASTNode.h>
#include <Compiler/Token.h>
#include <PL0/PL0Tokens.h>

#include <regex>
#include <string>
#include <vector>
namespace IKCL {

class ASTBuild {
   public:
    static std::vector<Token> Tokenizer(std::string input, bool ignoreWhitespace = false);
    static ASTNode Parser(std::vector<Token>);
};
}  // namespace IKCL
