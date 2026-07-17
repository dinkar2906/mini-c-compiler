#include "parser.h"

#include <cstdlib>
#include <iostream>

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
    parseProgram();

    std::cout << "Program Parsed Successfully\n";
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
    if(currentToken.type == TOK_INT)
    {
        parseDeclaration();
    }
    else if(currentToken.type == TOK_IDENTIFIER)
    {
        parseAssignment();
    }
    else if(currentToken.type == TOK_WHILE)
    {
        parseWhile();
    }
    else if(currentToken.type == TOK_RETURN)
    {
        parseReturn();
    }
    else
    {
        std::cout << "Unknown Statement\n";
        exit(1);
    }
}

void Parser::parseDeclaration()
{
    std::cout << "Parsing Declaration\n";

    expect(TOK_INT);
    expect(TOK_IDENTIFIER);
    expect(TOK_ASSIGN);

    parseExpression();

    expect(TOK_SEMICOLON);
}

void Parser::parseAssignment()
{
    std::cout << "Parsing Assignment\n";

    expect(TOK_IDENTIFIER);
    expect(TOK_ASSIGN);

    parseExpression();

    expect(TOK_SEMICOLON);
}

void Parser::parseExpression()
{
    parseTerm();

    while(currentToken.type == TOK_PLUS ||
          currentToken.type == TOK_MINUS)
    {
        advance();
        parseTerm();
    }
}

void Parser::parseTerm()
{
    if(currentToken.type == TOK_NUMBER)
    {
        expect(TOK_NUMBER);
    }
    else if(currentToken.type == TOK_IDENTIFIER)
    {
        expect(TOK_IDENTIFIER);
    }
    else
    {
        std::cout << "Expression Expected\n";
        exit(1);
    }
}

void Parser::parseWhile()
{
    std::cout << "Parsing While (Temporary)\n";

    advance();
}

void Parser::parseReturn()
{
    std::cout << "Parsing Return (Temporary)\n";

    advance();
}