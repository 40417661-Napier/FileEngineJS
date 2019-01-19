#include <stdlib.h>
#include <stdio.h>
#include "myfunctions.h"
//standard libs plus myfunctions file for modularisation

void main(){ //doesn't return anything

    char strInput[20]; //create "string" array [char array]
    printf("Enter your Name: \n"); //prompt
    fgets(strInput, 20, stdin); //readline
    removeNewLine(strInput); //see myfunctions.h for the code
    printf("%s is your name!\n", strInput); //outputs the input plus text

} //end