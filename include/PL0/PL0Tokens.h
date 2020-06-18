#pragma once
#include <regex>
#include <string>
#include <vector>
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

struct Pattern {
    Pattern(PL0Pattern t, std::regex r) {
        type = t;
        rep = r;
    }
    PL0Pattern type;
    std::regex rep;
};

std::vector<Pattern> Patterns = {
    Pattern(VAR, std::regex("VAR")),
    Pattern(CONST, std::regex("CONST")),
    Pattern(PROCEDURE, std::regex("PROCEDURE")),
    Pattern(CALL, std::regex("CALL")),
    Pattern(WHILE, std::regex("WHILE")),
    Pattern(DO, std::regex("DO")),
    Pattern(BEGIN, std::regex("BEGIN")),
    Pattern(END, std::regex("END")),
    Pattern(IDENTIFIER, std::regex("[a-z_][a-z0-9_]*")),
    Pattern(NUMBER, std::regex("[0-9]+")),
    Pattern(ASSIGNMENT, std::regex(":=")),
    Pattern(WRITE, std::regex("!")),
    Pattern(LPAREN, std::regex("\(")),
    Pattern(RPAREN, std::regex("\)")),
    Pattern(MULT, std::regex("\*")),
    Pattern(DIV, std::regex("\"))")),
    Pattern(PLUS, std::regex("\+")),
    Pattern(MINUS, std::regex("-")),
    Pattern(EQ, std::regex("=")),
    Pattern(NE, std::regex("#")),
    Pattern(LE, std::regex("<=")),
    Pattern(GE, std::regex(">=")),
    Pattern(LT, std::regex("<")),
    Pattern(GT, std::regex(">")),
    Pattern(COMMA, std::regex(",")),
    Pattern(PERIOD, std::regex("\.")),
    Pattern(SEMICOLON, std::regex(";")),
    Pattern(WHITESPACE, std::regex("\s"))
    }
