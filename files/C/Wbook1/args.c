#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"

int main(int argc, char **argv){

    for(int i=0; i < argc; i++){
        printf("arguement %d is: %s\n",i, argv[i]);
    }
    printf("All args printed\n");
}