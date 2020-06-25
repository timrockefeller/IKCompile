#pragma once

#include <Compiler/ASTNode.h>
#include <Compiler/Token.h>
#include <PL0/PL0Grammar.h>
#include <PL0/PL0Patterns.h>

#include <regex>
#include <string>
#include <vector>

/**
 * PL/0 recursive descent parser
 * 
 * https://en.wikipedia.org/wiki/Recursive_descent_parser
 * 
 * program = block "." .
 *
 * block = [ "const" ident "=" number {"," ident "=" number} ";"]
 *         [ "var" ident {"," ident} ";"]
 *         { "procedure" ident ";" block ";" } statement .
 *
 * statement = [ ident ":=" expression | "call" ident 
 *               | "?" ident | "!" expression 
 *               | "begin" statement {";" statement } "end" 
 *               | "if" condition "then" statement 
 *               | "while" condition "do" statement ].
 *
 * condition = "odd" expression |
 *             expression ("="|"#"|"<"|"<="|">"|">=") expression .
 *
 * expression = [ "+"|"-"] term { ("+"|"-") term}.
 *
 * term = factor {("*"|"/") factor}.
 *
 * factor = ident | number | "(" expression ")".
 *
 */

namespace IKCL {
using PL0Token = Token<PL0Pattern>;
using PL0Tokens = std::vector<PL0Token>;
using PL0AST = ASTNode<PL0ASTType>;
class ASTBuild {
   private:
    static PL0Token curToken;
    static int curIndex;
    static PL0Tokens allTokens;

    static bool accept(PL0Pattern);
    static bool expect(PL0Pattern);
    static PL0Token prevToken(int = 0);
    static void nextToken();

    // parser
    static ProgramNode parseProgram();
    static BlockNode parseBlock();
    static ASTNode<PL0ASTType> parseStatement();
    static ExpressionNode parseExpression();
    static ASTNode<PL0ASTType> parseCondition();

    static void parseFactor();
    static void parseTerm();

   public:
    static void Init();
    static PL0Tokens Tokenizer(std::string input, bool ignoreWhitespace = false);
    static PL0AST Parser(PL0Tokens);
};
}  // namespace IKCL
