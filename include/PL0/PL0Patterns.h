#pragma once
#include <Compiler/Pattern.h>

#include <regex>
#include <string>
#include <vector>
namespace IKCL {
enum PL0Pattern {
    VAR,
    CONST,
    PROCEDURE,
    CALL,
    WHILE,
    DO,
    BEGIN,
    END,
    IDENTIFIER,
    NUMBER,
    ASSIGNMENT,
    WRITE,
    LPAREN,
    RPAREN,
    MULT,
    DIV,
    PLUS,
    MINUS,
    EQ,
    NE,
    LE,
    GE,
    LT,
    GT,
    COMMA,
    PERIOD,
    SEMICOLON,
    WHITESPACE
};

std::vector<Pattern<PL0Pattern>> PL0Patterns = {
    Pattern<PL0Pattern>(VAR, std::regex("VAR")),
    Pattern<PL0Pattern>(CONST, std::regex("CONST")),
    Pattern<PL0Pattern>(PROCEDURE, std::regex("PROCEDURE")),
    Pattern<PL0Pattern>(CALL, std::regex("CALL")),
    Pattern<PL0Pattern>(WHILE, std::regex("WHILE")),
    Pattern<PL0Pattern>(DO, std::regex("DO")),
    Pattern<PL0Pattern>(BEGIN, std::regex("BEGIN")),
    Pattern<PL0Pattern>(END, std::regex("END")),
    Pattern<PL0Pattern>(IDENTIFIER, std::regex("[a-z_][a-z0-9_]*")),
    Pattern<PL0Pattern>(NUMBER, std::regex("[0-9]+")),
    Pattern<PL0Pattern>(ASSIGNMENT, std::regex(":=")),
    Pattern<PL0Pattern>(WRITE, std::regex("!")),
    Pattern<PL0Pattern>(LPAREN, std::regex("\\(")),
    Pattern<PL0Pattern>(RPAREN, std::regex("\\)")),
    Pattern<PL0Pattern>(MULT, std::regex("\\*")),
    Pattern<PL0Pattern>(DIV, std::regex("\\\\")),
    Pattern<PL0Pattern>(PLUS, std::regex("\\+")),
    Pattern<PL0Pattern>(MINUS, std::regex("-")),
    Pattern<PL0Pattern>(EQ, std::regex("=")),
    Pattern<PL0Pattern>(NE, std::regex("#")),
    Pattern<PL0Pattern>(LE, std::regex("<=")),
    Pattern<PL0Pattern>(GE, std::regex(">=")),
    Pattern<PL0Pattern>(LT, std::regex("<")),
    Pattern<PL0Pattern>(GT, std::regex(">")),
    Pattern<PL0Pattern>(COMMA, std::regex(",")),
    Pattern<PL0Pattern>(PERIOD, std::regex("\\.")),
    Pattern<PL0Pattern>(SEMICOLON, std::regex(";")),
    Pattern<PL0Pattern>(WHITESPACE, std::regex("\\s"))};
}  // namespace IKCL
