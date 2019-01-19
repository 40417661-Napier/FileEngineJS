#include <stdio.h>

void foo(int * x_ptr)
{
    printf("Address of x in function = %p\n", x_ptr);
    printf("Start of function , x = %d\n", *x_ptr);
    *x_ptr = 20;
    printf("End of function, x = %d\n", *x_ptr);
    printf("Address of x at end of function = %p\n", x_ptr);
}

int main(int argc, char **argv)
{
    int x = 10;
    printf("Starting address of x = %p\n", &x);
    printf("Before function call, x = %d\n", x);
    foo(&x);
    printf("After function call, x = %d\n", x);
    printf("End address of x = %p\n", &x);
    return 0;
}
