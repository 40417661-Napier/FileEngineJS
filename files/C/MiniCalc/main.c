#include <stdio.h>
#include <stdlib.h>

void do_calc(){

    int x, y, sum;
    printf("Enter the first int: \n");
    scanf("%d", &x);
    printf("Enter the second int: \n");
    scanf("%d", &y);
    sum = addnum(x,y);
    printf("The sum of %d and %d is %d\n", x, y, sum);
    sum = squareNums(x, y);
    printf("The sum of %d squared and %d squared is %d", x, y, sum);
    x = 2;

}

int main()
{
    do_calc();
    return 0;
}
