#include "myfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char x[32];
    int sum = atoi(x);
    int loopInt = 1;
    int intVar;
    printf("Enter numbers to add up, type 0 to end the program:\n");
    sumRun(sum);
    printf("%d", sum);
    return 0;
}

