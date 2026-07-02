#ifndef TOKEN_H
#define TOKEN_H

enum TokenType
{
    TOK_EOF,

    TOK_IDENTIFIER,
    TOK_NUMBER,
    TOK_STRING,
    TOK_CHAR,

    TOK_INT,
    TOK_RETURN,
    TOK_IF,
    TOK_ELSE,
    TOK_WHILE,

    TOK_PLUS,
    TOK_MINUS,
    TOK_STAR,
    TOK_SLASH,

    TOK_ASSIGN,

    TOK_LPAREN,
    TOK_RPAREN,

    TOK_LBRACE,
    TOK_RBRACE,

    TOK_SEMICOLON
};

struct Token
{
    TokenType type;
    const char* lexeme;
};

#endif