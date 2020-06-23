#pragma once
#include <Compiler/Pattern.h>

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
    IF,
    THEN,
    ODD,
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

extern std::vector<Pattern<PL0Pattern>> PL0PatternReg;

}  // namespace IKCL
