#include "myfunctions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char name[32];
    char age[32];
    int ageVal;
    printf("What is your name?: \n");
    fgets(name, 50, stdin);
    printf("What is your age?: \n");
    fgets(age, 50, stdin);
    ageVal = atoi(age);

    removeNewLine(name);

    printf("There is an attached variable in this output with the name value of %s and the age of %d \n",name, ageVal);
    return 0;
}