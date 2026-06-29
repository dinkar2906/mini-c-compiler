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
    static char buffer[256];

    while (currentChar() != '\0')
    {
        // Skip spaces
        if (isspace(currentChar()))
        {
            advance();
            continue;
        }

        // Number
        if (isdigit(currentChar()))
        {
            int i = 0;

            while (isdigit(currentChar()))
            {
                buffer[i++] = currentChar();
                advance();
            }

            buffer[i] = '\0';

            Token token;
            token.type = TOK_NUMBER;
            token.lexeme = buffer;

            return token;
        }

        // Identifier
        if (isalpha(currentChar()) || currentChar() == '_')
        {
            int i = 0;

            while (isalnum(currentChar()) || currentChar() == '_')
            {
                buffer[i++] = currentChar();
                advance();
            }

            buffer[i] = '\0';

            Token token;
            token.type = TOK_IDENTIFIER;
            token.lexeme = buffer;

            return token;
        }

        // Ignore unknown characters
        advance();
    }

    Token token;
    token.type = TOK_EOF;
    token.lexeme = "";

    return token;
}