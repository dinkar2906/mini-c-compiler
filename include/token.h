#ifndef TOKEN_H
#define TOKEN_H

enum TokenType
{
    TOK_INT,
    TOK_IF,
    TOK_ELSE,
    TOK_WHILE,
    TOK_RETURN,

    TOK_IDENTIFIER,
    TOK_NUMBER,

    TOK_PLUS,
    TOK_MINUS,
    TOK_STAR,
    TOK_SLASH,

    TOK_ASSIGN,
    TOK_SEMICOLON,

    TOK_LPAREN,
    TOK_RPAREN,
    TOK_LBRACE,
    TOK_RBRACE,

    TOK_EOF
};

struct Token
{
    TokenType type;
    char lexeme[64];
};

#endif