#include "parser.h"

int main()
{
    Parser parser(
R"(

int main()
{
}

)"
);

    parser.parse();

    return 0;
}