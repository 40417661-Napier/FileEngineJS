#include <stdio.h>

void foo(int x)
{
    printf("Start of function, x = %d\n", x);
    x = 20;
    printf("End of function, x = %d\n", x);
}

int main(int argc, char **argv)
{
    int x = 10;
    printf("Before function call, x = %d\n", x);
    foo(x);
    printf("After function call, x = %d\n", x);
    return 0;
}
