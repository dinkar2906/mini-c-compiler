#include "lexer.h"
#include <cctype>

Lexer::Lexer(const char* src)
{
    source = src;
    pos = 0;
}

char Lexer::currentChar()
{
    return source[pos];
}

void Lexer::advance()
{
    pos++;
}

Token Lexer::nextToken()
{
    Token token;

    while (currentChar() != '\0')
    {
        if (isdigit(currentChar()))
        {
            while (isdigit(currentChar()))
            {
                advance();
            }

            token.type = TOK_NUMBER;
            token.lexeme = "NUMBER";

            return token;
        }

        advance();
    }

    token.type = TOK_EOF;
    token.lexeme = "EOF";

    return token;
}