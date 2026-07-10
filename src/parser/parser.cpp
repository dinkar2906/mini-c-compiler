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

void Parser::parseProgram()
{
    parseFunction();
}

void Parser::parseFunction()
{
    std::cout << "Parsing Function\n";

    expect(TOK_INT);

    expect(TOK_IDENTIFIER);

    expect(TOK_LPAREN);

    expect(TOK_RPAREN);

    parseBlock();
}

void Parser::parseBlock()
{
    std::cout << "Parsing Block\n";

    expect(TOK_LBRACE);

    parseStatementList();

    expect(TOK_RBRACE);
}

void Parser::parseStatementList()
{
    while(currentToken.type != TOK_RBRACE &&
          currentToken.type != TOK_EOF)
    {
        parseStatement();
    }
}

void Parser::parseStatement()
{
    std::cout 
        << "Statement found: "
        << currentToken.lexeme
        << '\n';

    advance();
}


void Parser::parse()
{
    parseProgram();

    std::cout << "Program Parsed Successfully\n";
}