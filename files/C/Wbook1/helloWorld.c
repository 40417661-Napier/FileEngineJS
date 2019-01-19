#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeNewLine(char name[]);

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

void removeNewLine(char name[]){
    int len = strlen(name);
    if(len > 0 && name[len-1] == '\n'){
        name[len-1] = '\0';
    }
}