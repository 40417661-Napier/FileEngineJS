#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeNewLine(char name[]){
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
    {
        name[len - 1] = '\0';
    }
}

void sumRun(int sum){
    char x[32];
    int loopInt = 1;
    int intVar;
    fgets(x, 32, stdin);
    intVar = atoi(x);
    sum = sum + intVar;
    if(intVar == 0){
        printf("sum of numbers: %d\n", sum);
    }else{
        sumRun(sum);
    }
}