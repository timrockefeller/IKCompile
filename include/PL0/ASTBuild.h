#pragma once

#include <Compiler/ASTNode.h>
#include <Compiler/Token.h>
#include <PL0/PL0Tokens.h>
#include <PL0/PL0Grammar.h>

#include <regex>
#include <string>
#include <vector>
namespace IKCL {

class ASTBuild {
   public:
    static std::vector<Token<PL0Pattern>> Tokenizer(std::string input, bool ignoreWhitespace = false);
    static ASTNode<PL0ASTType> Parser(std::vector<Token<PL0Pattern>>);
};
}  // namespace IKCL
