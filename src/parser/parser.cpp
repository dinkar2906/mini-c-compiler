#include "parser.h"

#include <iostream>
#include <cstdlib>

Parser::Parser(const char* source)
    : lexer(source)
{
    currentToken = lexer.nextToken();
}

void Parser::advance()
{
    currentToken = lexer.nextToken();
}

void Parser::expect(TokenType type)
{
    if(currentToken.type == type)
    {
        advance();
    }
    else
    {
        std::cout << "Syntax Error\n";
        exit(1);
    }
}

void Parser::parse()
{
    std::cout << "Parser Started\n";
}