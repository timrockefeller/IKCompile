#include <Compiler/ASTNode.h>
#include <Compiler/Pattern.h>
#include <Compiler/Token.h>
#include <PL0/ASTBuild.h>
#include <PL0/PL0Grammar.h>
#include <PL0/PL0Patterns.h>
using namespace std;
using namespace IKCL;

PL0Tokens ASTBuild::Tokenizer(string input, bool ignoreWhitespace) {
    size_t cur = 0;
    const size_t LENGTH = input.length();

    // char* origin = new char[LENGTH];
    // memcmp(origin, input.c_str(), LENGTH);
    const char* origin = input.c_str();
    PL0Tokens result;

    while (cur < LENGTH) {
        bool tokenized = false;
        for (Pattern<PL0Pattern> pattern : PL0PatternReg) {
            cmatch rerResult;
            bool bValid = regex_search(origin + cur, rerResult, pattern.rep);
            if (bValid && rerResult.position() == 0) {
                tokenized = true;

                size_t strlength = rerResult.length();
                string strval = rerResult.str();
                if (pattern.type != WHITESPACE || !ignoreWhitespace) {
                    Token<PL0Pattern> token;
                    token.token = pattern.type;
                    token.length = strlength;
                    token.strval = strval;
                    try {
                        token.intval = stoi(strval);
                        token.floatval = stof(strval);
                    } catch (const std::invalid_argument&) {
                    } catch (const std::out_of_range&) {
                    } catch (const std::exception&){}
                    result.push_back(token);
                }
                cur += strlength;
                break;
            }
        }
        if (!tokenized) {
            throw string(origin + cur).substr(0, 10);
        }
    }
    return result;
}

PL0AST ASTBuild::Parser(PL0Tokens) {
    return PL0AST();
}
