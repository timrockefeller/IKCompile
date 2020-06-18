#include <PL0/PL0Patterns.h>

#include <regex>

using namespace IKCL;
using namespace std;
vector<Pattern<PL0Pattern>> IKCL::PL0PatternReg = {
    Pattern<PL0Pattern>(VAR, regex("VAR")),
    Pattern<PL0Pattern>(CONST, regex("CONST")),
    Pattern<PL0Pattern>(PROCEDURE, regex("PROCEDURE")),
    Pattern<PL0Pattern>(CALL, regex("CALL")),
    Pattern<PL0Pattern>(WHILE, regex("WHILE")),
    Pattern<PL0Pattern>(DO, regex("DO")),
    Pattern<PL0Pattern>(BEGIN, regex("BEGIN")),
    Pattern<PL0Pattern>(END, regex("END")),
    Pattern<PL0Pattern>(IDENTIFIER, regex("[a-z_][a-z0-9_]*")),
    Pattern<PL0Pattern>(NUMBER, regex("[0-9]+")),
    Pattern<PL0Pattern>(ASSIGNMENT, regex(":=")),
    Pattern<PL0Pattern>(WRITE, regex("!")),
    Pattern<PL0Pattern>(LPAREN, regex("\\(")),
    Pattern<PL0Pattern>(RPAREN, regex("\\)")),
    Pattern<PL0Pattern>(MULT, regex("\\*")),
    Pattern<PL0Pattern>(DIV, regex("\\\\")),
    Pattern<PL0Pattern>(PLUS, regex("\\+")),
    Pattern<PL0Pattern>(MINUS, regex("-")),
    Pattern<PL0Pattern>(EQ, regex("=")),
    Pattern<PL0Pattern>(NE, regex("#")),
    Pattern<PL0Pattern>(LE, regex("<=")),
    Pattern<PL0Pattern>(GE, regex(">=")),
    Pattern<PL0Pattern>(LT, regex("<")),
    Pattern<PL0Pattern>(GT, regex(">")),
    Pattern<PL0Pattern>(COMMA, regex(",")),
    Pattern<PL0Pattern>(PERIOD, regex("\\.")),
    Pattern<PL0Pattern>(SEMICOLON, regex(";")),
    Pattern<PL0Pattern>(WHITESPACE, regex("\\s"))};
