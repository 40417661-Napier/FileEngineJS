#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char x[32];
    int sum = atoi(x);
    int loopInt = 1;
    int intVar;
    printf("Enter numbers to add up, type 0 to end the program:\n");
    while(loopInt){
        fgets(x, 32, stdin);
        intVar = atoi(x);
        sum = sum + intVar;
        if(intVar == 0){
            printf("sum of numbers: %d\n", sum);
            return 0;
        }

    }
    printf("%d", sum);
    return 0;
}