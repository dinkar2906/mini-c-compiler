#include "lexer.h"

#include <cctype>
#include <cstring>

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

TokenType Lexer::checkKeyword(const char* word)
{
    if (strcmp(word, "int") == 0)
    {
        return TOK_INT;
    }

    if (strcmp(word, "return") == 0)
    {
        return TOK_RETURN;
    }

    if (strcmp(word, "if") == 0)
    {
        return TOK_IF;
    }

    if (strcmp(word, "else") == 0)
    {
        return TOK_ELSE;
    }

    if (strcmp(word, "while") == 0)
    {
        return TOK_WHILE;
    }

    return TOK_IDENTIFIER;
}

Token Lexer::nextToken()
{
    static char buffer[256];

    while (currentChar() != '\0')
    {
        // Skip whitespace
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

        // Identifier / Keyword
        if (isalpha(currentChar()) || currentChar() == '_')
        {
            int i = 0;

            while (isalnum(currentChar()) || currentChar() == '_')
            {
                buffer[i++] = currentChar();
                advance();
            }

            buffer[i] = '\0'; // to make a proper cstring

            Token token;
            token.type = checkKeyword(buffer);
            token.lexeme = buffer;

            return token;
        }

        // Ignore unknown character
        advance();
    }

    Token token;
    token.type = TOK_EOF;
    token.lexeme = "";

    return token;
}