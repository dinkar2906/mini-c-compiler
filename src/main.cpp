#include <iostream>
#include "lexer.h"

int main()
{
    Lexer lexer("123");

    Token token = lexer.nextToken();

    std::cout << token.lexeme << '\n';

    return 0;
}