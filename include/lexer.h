#ifndef LEXER_H
#define LEXER_H

#include "token.h"

class Lexer
{
private:
    private:
    const char* source;
    int pos;
    int line;

    char currentChar();
    char peekChar();
    void advance();

    TokenType checkKeyword(const char* word);

    Token makeToken(TokenType type, const char* lexeme);

public:
    Lexer(const char* src);

    Token nextToken();
};

#endif