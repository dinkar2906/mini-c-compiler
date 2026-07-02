#include "lexer.h"

#include <cctype>
#include <cstring>
#include <cstdio>

Lexer::Lexer(const char* src)
{
    source = src;
    pos = 0;
    line = 1;
}

char Lexer::currentChar()
{
    return source[pos];
}


char Lexer::peekChar()
{
    if (currentChar() == '\0')
    {
        return '\0';
    }

    return source[pos + 1];
}

void Lexer::advance()
{
    
    if (currentChar() == '\n')
    {
        line++;
    }

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
        
        if (isspace(currentChar()))
        {
            advance();
            continue;
        }

        
        if (currentChar() == '/' && peekChar() == '/')
        {
            while (currentChar() != '\n' && currentChar() != '\0')
            {
                advance();
            }
            continue;
        }

        
        if (currentChar() == '/' && peekChar() == '*')
        {
            advance(); // skip '/'
            advance(); // skip '*'

            while (!(currentChar() == '*' && peekChar() == '/'))
            {
                if (currentChar() == '\0')
                {
                    printf("Lexer Error (line %d): comment was never closed with */\n", line);
                    break;
                }
                advance();
            }

            if (currentChar() != '\0')
            {
                advance(); // skip '*'
                advance(); // skip '/'
            }

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

        // String literal: "like this"
        if (currentChar() == '"')
        {
            advance(); // skip opening quote

            int i = 0;

            while (currentChar() != '"' && currentChar() != '\0')
            {
                buffer[i++] = currentChar();
                advance();
            }

            if (currentChar() == '\0')
            {
                printf("Lexer Error (line %d): string was never closed with \"\n", line);
            }
            else
            {
                advance(); // skip closing quote
            }

            buffer[i] = '\0';

            Token token;
            token.type = TOK_STRING;
            token.lexeme = buffer;

            return token;
        }

        // Character literal: 'like this'
        if (currentChar() == '\'')
        {
            advance(); // skip opening quote

            int i = 0;

            while (currentChar() != '\'' && currentChar() != '\0')
            {
                buffer[i++] = currentChar();
                advance();
            }

            if (currentChar() == '\0')
            {
                printf("Lexer Error (line %d): character literal was never closed with '\n", line);
            }
            else
            {
                advance(); // skip closing quote
            }

            buffer[i] = '\0';

            Token token;
            token.type = TOK_CHAR;
            token.lexeme = buffer;

            return token;
        }

        // Operators: + - * / =
        if (currentChar() == '+')
        {
            advance();
            Token token;
            token.type = TOK_PLUS;
            token.lexeme = "+";
            return token;
        }

        if (currentChar() == '-')
        {
            advance();
            Token token;
            token.type = TOK_MINUS;
            token.lexeme = "-";
            return token;
        }

        if (currentChar() == '*')
        {
            advance();
            Token token;
            token.type = TOK_STAR;
            token.lexeme = "*";
            return token;
        }

        if (currentChar() == '/')
        {
            advance();
            Token token;
            token.type = TOK_SLASH;
            token.lexeme = "/";
            return token;
        }

        if (currentChar() == '=')
        {
            advance();
            Token token;
            token.type = TOK_ASSIGN;
            token.lexeme = "=";
            return token;
        }

        // Delimiters: ( ) { } ;
        if (currentChar() == '(')
        {
            advance();
            Token token;
            token.type = TOK_LPAREN;
            token.lexeme = "(";
            return token;
        }

        if (currentChar() == ')')
        {
            advance();
            Token token;
            token.type = TOK_RPAREN;
            token.lexeme = ")";
            return token;
        }

        if (currentChar() == '{')
        {
            advance();
            Token token;
            token.type = TOK_LBRACE;
            token.lexeme = "{";
            return token;
        }

        if (currentChar() == '}')
        {
            advance();
            Token token;
            token.type = TOK_RBRACE;
            token.lexeme = "}";
            return token;
        }

        if (currentChar() == ';')
        {
            advance();
            Token token;
            token.type = TOK_SEMICOLON;
            token.lexeme = ";";
            return token;
        }

        // Unknown character: report it and skip past it
        printf("Lexer Error (line %d): unexpected character '%c'\n", line, currentChar());
        advance();
    }

    Token token;
    token.type = TOK_EOF;
    token.lexeme = "";

    return token;
}