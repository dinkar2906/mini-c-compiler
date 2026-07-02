#include <iostream>
#include "lexer.h"

const char* tokenToString(TokenType type)
{
    switch(type)
    {
        case TOK_EOF:        return "EOF";
        case TOK_IDENTIFIER: return "IDENTIFIER";
        case TOK_NUMBER:     return "NUMBER";
        case TOK_INT:        return "INT";
        case TOK_RETURN:     return "RETURN";
        case TOK_IF:         return "IF";
        case TOK_ELSE:       return "ELSE";
        case TOK_WHILE:      return "WHILE";
        default:             return "UNKNOWN";
    }
}

int main()
{
    Lexer lexer("int count return while if else abc 123");

    Token token;

    do
    {
        token = lexer.nextToken();

        std::cout << tokenToString(token.type)
                  << " -> "
                  << token.lexeme
                  << '\n';

    } while(token.type != TOK_EOF);

    return 0;
}