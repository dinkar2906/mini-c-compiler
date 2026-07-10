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

    //2
    void parseStatementList();
    
    // 3
    void parseStatement();

public:

    Parser(const char* source);

    void parse();
};

#endif