#ifndef AST_H
#define AST_H

enum NodeType
{
    NODE_NUMBER,
    NODE_VARIABLE,
    NODE_BINARY,
    NODE_ASSIGN
};

struct ASTNode
{
    NodeType type;

    ASTNode* left;
    ASTNode* right;

    int value;
};

#endif