class Lexer
{
private:
    const char* source;
    int pos;

public:
    Lexer(const char* src);

    Token nextToken();
};