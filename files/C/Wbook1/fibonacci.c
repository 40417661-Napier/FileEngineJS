#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"

void main(int argc, char **argv){

    int x = 1;
    int num1 = 0;
    int oldNum1 = 1;
    int oldOldnum1;
    char buffer[100];
    int runTo;

    if(argc < 2){

        printf("Which element of the fibonacci sequence would you like?: ");
        fgets(buffer, 100, stdin);
        runTo = atoi(buffer);

    }else{

        runTo = atoi(argv[1]);

    }

    while(x < runTo+1){
        
        oldOldnum1 = num1 + oldNum1; 
        num1 = oldNum1;
        oldNum1 = oldOldnum1; 
        printf("%d\n", num1);
        x++;
    }
    

}