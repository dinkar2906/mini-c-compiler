#include "parser.h"

int main()
{
    Parser parser(
R"(

int main()
{
    int x = 10;

    x = x - 1;

    while(x)
    {
    }

    return x;
}

)"
);

    parser.parse();

    return 0;
}