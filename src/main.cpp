#include "parser.h"

int main()
{
    Parser parser(
R"(

int main()
{
    int x = 10;

    x = x - 1;
}

)"
    );

    parser.parse();

    return 0;
}