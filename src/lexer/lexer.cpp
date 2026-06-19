#ifndef LEXER_H
#define LEXER_H

#include "token.h"

class Lexer
{
private:
    const char* source;
    int pos;

    char currentChar();
    void advance();

public:
    Lexer(const char* src);

    Token nextToken();
};

#endif