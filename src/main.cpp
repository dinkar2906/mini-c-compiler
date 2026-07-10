#include "parser.h"

int main()
{
    Parser parser(
R"(

int main()
{
    int x = 10;
}

)"
);

    parser.parse();

    return 0;
}