#include <Compiler/ASTNode.h>
#include <Compiler/Pattern.h>
#include <Compiler/Token.h>
#include <PL0/ASTBuild.h>
#include <PL0/PL0Grammar.h>
#include <PL0/PL0Patterns.h>
using namespace std;
using namespace IKCL;
PL0Token ASTBuild::curToken = PL0Token();
int ASTBuild::curIndex = 0;
PL0Tokens ASTBuild::allTokens = PL0Tokens();
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
                    } catch (const std::exception&) {
                    }
                    result.push_back(token);
                }
                cur += strlength;
                break;
            }
        }
        if (!tokenized) {
            throw "[!!] Unexpected Token at :" + string(origin + cur).substr(0, 10);
        }
    }
    return result;
}

PL0AST ASTBuild::Parser(PL0Tokens tokens) {
    allTokens = tokens;
    curToken = allTokens[0];

    ProgramNode p = parseProgram();
    return (PL0AST)p;
}

bool ASTBuild::accept(PL0Pattern token) {
    if (curToken.token == token) {
        nextToken();
        return true;
    }

    return false;
}
bool ASTBuild::expect(PL0Pattern token) {
    if (!accept(token))
        throw "[!!] Unexpected symbol: " + curToken.strval;
    return true;
}
/**
 * Get previous tokens without changing curToken
 */
PL0Token ASTBuild::prevToken(int n) {
    return allTokens[curIndex - n - 2];
}

/**
 *  Take the next token off the front of the list
 */
void ASTBuild::nextToken() {
    curToken = allTokens[curIndex];
    curIndex++;
}

ProgramNode ASTBuild::parseProgram() {
    nextToken();
    ProgramNode astnode;
    astnode.block = parseBlock();
    return astnode;
}
BlockNode ASTBuild::parseBlock() {
    BlockNode astnode;
    if (accept(CONST)) {
        do {
            expect(IDENTIFIER);
            expect(EQ);
            expect(NUMBER);
            SymbolNode s;
            s.isConst = true;
            s.val = (float)prevToken().intval;
            pair<string, SymbolNode> sr(prevToken(2).strval, s);
            astnode.symbol.insert(sr);
        } while (accept(COMMA));

        expect(SEMICOLON);
    }

    if (accept(VAR)) {
        do {
            expect(IDENTIFIER);
            SymbolNode s;
            s.isConst = false;
            pair<string, SymbolNode> sr(prevToken().strval, s);

            astnode.symbol.insert(sr);
        } while (accept(COMMA));
        expect(SEMICOLON);
    }

    while (accept(PROCEDURE)) {
        expect(IDENTIFIER);
        string id = prevToken().strval;
        expect(SEMICOLON);
        BlockNode b = parseBlock();
        expect(SEMICOLON);
        ProcedureNode p;
        p.name = id;
        p.block = b;
        astnode.procedure.push_back(p);
    }

    astnode.statement = parseStatement();

    return astnode;
}
ASTNode<PL0ASTType> ASTBuild::parseStatement() {
    ASTNode<PL0ASTType> astNode;
    if (accept(IDENTIFIER)) {
        expect(ASSIGNMENT);
        AssignmentNode a;
        a.identifier = prevToken(1).strval;
        parseExpression();
        astNode = (ASTNode<PL0ASTType>)a;
    } else if (accept(CALL)) {
        expect(IDENTIFIER);
        CallNode a;
        a.identifier = prevToken().strval;
        astNode = (ASTNode<PL0ASTType>)a;
    } else if (accept(WRITE)) {
        parseExpression();
        WriteNode a;
        a.identifier = prevToken().strval;
        astNode = (ASTNode<PL0ASTType>)a;
    } else if (accept(BEGIN)) {
        CompoundStatementNode a;
        do {
            a.statements.push_back(parseStatement());
        } while (accept(SEMICOLON));
        expect(END);
        astNode = (ASTNode<PL0ASTType>)a;
    } else if (accept(IF)) {
        IfThenNode a;
        a.condition = parseCondition();
        expect(THEN);
        a.statement = parseStatement();
        astNode = (ASTNode<PL0ASTType>)a;
    } else if (accept(WHILE)) {
        WhileNode a;
        a.condition = parseCondition();
        expect(DO);
        a.statement = parseStatement();
        astNode = (ASTNode<PL0ASTType>)a;
    } else {
        throw "[!!] syntax error: " + curToken.strval;
    }

    return astNode;
}
ASTNode<PL0ASTType> ASTBuild::parseCondition() {
    ASTNode<PL0ASTType> astNode = ASTNode<PL0ASTType>();

    if (accept(ODD)) {
        parseExpression();
    } else {
        parseExpression();
        if (accept(EQ) ||
            accept(NE) ||
            accept(LT) ||
            accept(LE) ||
            accept(GT) ||
            accept(GE)) {
            parseExpression();
        } else {
            throw "[!!] condition: invalid operator: " + curToken.strval;
        }
    }
    return astNode;
}
void ASTBuild::parseFactor() {
    if (accept(IDENTIFIER)) {
    } else if (accept(NUMBER)) {
    } else if (accept(LPAREN)) {
        parseExpression();
        expect(RPAREN);
    } else {
        throw "[!!] syntax error: " + curToken.strval;
    }
}

void ASTBuild::parseTerm() {
    parseFactor();
    while (accept(MULT) || accept(DIV)) {
        parseFactor();
    }
}
ExpressionNode ASTBuild::parseExpression() {
    if (accept(PLUS) || accept(MINUS)) {
    }
    parseTerm();
    while (accept(PLUS) || accept(MINUS)) {
        parseTerm();
    }
    return ExpressionNode();
}
int ASTBuild::getCurIndex(){
    return curIndex;
}
void ASTBuild::Init() {
    curIndex = 0;
}
