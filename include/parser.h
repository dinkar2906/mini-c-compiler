#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

class Parser
{
private:

    Lexer lexer;
    Token currentToken;

    void advance();
    void expect(TokenType type);

    // Grammar Rules
    void parseProgram();
    void parseFunction();
    void parseBlock();
    void parseStatementList();
    void parseStatement();

    void parseDeclaration();
    void parseAssignment();
    void parseWhile();
    void parseReturn();

    void parseExpression();
    void parseTerm();

public:

    Parser(const char* source);

    void parse();
};

#endif