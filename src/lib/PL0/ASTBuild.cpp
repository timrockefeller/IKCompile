#include <Compiler/ASTNode.h>
#include <Compiler/Pattern.h>
#include <Compiler/Token.h>
#include <PL0/ASTBuild.h>
#include <PL0/PL0Grammar.h>
#include <PL0/PL0Tokens.h>
using namespace std;
using namespace IKCL;

vector<Token<PL0Pattern>> ASTBuild::Tokenizer(string input, bool ignoreWhitespace) {
    size_t cur = 0;
    const size_t LENGTH = input.length();

    char* origin = new char[LENGTH];
    memcmp(origin, input.c_str(), LENGTH);

    vector<Token<PL0Pattern>> result;

    while (cur < LENGTH) {
        bool tokenized = false;
        for (Pattern<PL0Pattern> pattern : PL0Patterns) {
            cmatch rerResult;
            bool bValid = regex_match(origin + cur, rerResult, pattern.rep);
            if (bValid && rerResult.position() == 0) {
                tokenized = true;

                size_t strlength = rerResult.length();
                string strval = rerResult.str();
                if (pattern.type != WHITESPACE || !ignoreWhitespace) {
                    Token<PL0Pattern> token;
                    token.token = pattern.type;
                    token.length = strlength;
                    token.strval = strval;
                    token.intval = stoi(strval);
                    token.floatval = stof(strval);
                    result.push_back(token);
                }
                cur += strlength;
                break;
            }
        }
        if (!tokenized) {
            throw "Unrecognized token at:" + string(origin + cur).substr(0, 10);
        }
    }
}

ASTNode<PL0ASTType> ASTBuild::Parser(vector<Token<PL0Pattern>>) {
}
