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

    // Grammar
    void parseProgram();
    void parseFunction();
    void parseBlock();
    void parseStatementList();

public:

    Parser(const char* source);

    void parse();
};

#endif