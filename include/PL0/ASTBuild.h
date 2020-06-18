#pragma once

#include <Compiler/ASTNode.h>
#include <Compiler/Token.h>
#include <PL0/PL0Patterns.h>
#include <PL0/PL0Grammar.h>

#include <regex>
#include <string>
#include <vector>
namespace IKCL {
using PL0Tokens = std::vector<Token<PL0Pattern>>;
using PL0AST = ASTNode<PL0ASTType>;
class ASTBuild {
   public:
    static PL0Tokens Tokenizer(std::string input, bool ignoreWhitespace = false);
    static PL0AST Parser(PL0Tokens);
};
}  // namespace IKCL
