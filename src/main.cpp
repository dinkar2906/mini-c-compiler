#include <iostream>
#include "lexer.h"

int main()
{
    Lexer lexer("123 abc 456 xyz");

    Token token;

    do
    {
        token = lexer.nextToken();

        std::cout << token.type
                  << " -> "
                  << token.lexeme
                  << '\n';

    } while (token.type != TOK_EOF);

    return 0;
}