#include <iostream>

#include "lexer.h"

const char* tokenToString(TokenType type)
{
    switch(type)
    {
        case TOK_EOF:         return "EOF";

        case TOK_IDENTIFIER:  return "IDENTIFIER";
        case TOK_NUMBER:      return "NUMBER";
        case TOK_STRING:      return "STRING";
        case TOK_CHAR:        return "CHAR";

        case TOK_INT:         return "INT";
        case TOK_RETURN:      return "RETURN";
        case TOK_IF:          return "IF";
        case TOK_ELSE:        return "ELSE";
        case TOK_WHILE:       return "WHILE";

        case TOK_PLUS:        return "PLUS";
        case TOK_MINUS:       return "MINUS";
        case TOK_STAR:        return "STAR";
        case TOK_SLASH:       return "SLASH";
        case TOK_ASSIGN:      return "ASSIGN";

        case TOK_LPAREN:      return "LPAREN";
        case TOK_RPAREN:      return "RPAREN";
        case TOK_LBRACE:      return "LBRACE";
        case TOK_RBRACE:      return "RBRACE";

        case TOK_SEMICOLON:   return "SEMICOLON";
    }

    return "UNKNOWN";
}

int main()
{
    Lexer lexer(
R"(

// Sample Program

int main()
{
    int x = 10;

    // decrement

    while(x)
    {
        x = x - 1;
    }

    char c = 'A';

    "Hello Compiler"

    return x;
}

)"
);

    Token token;

    do
    {
        token = lexer.nextToken();

        std::cout
            << tokenToString(token.type)
            << " -> "
            << token.lexeme
            << '\n';

    } while(token.type != TOK_EOF);

    return 0;
}