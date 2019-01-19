#include <stdlib.h>
#include <stdio.h>
#include "generate.h"
#include "sort.h"
#include "search.h"

#define NUM_INTEGERS 65535

int main(int argc, char **argv)
{
    //  Allocate  an  array of a given  size
    int data[NUM_INTEGERS];
    //  Generate  random  numbers
    generate(NUM_INTEGERS, data);
    //  Output  first 20  values
    printf("\nUnsorted\n");
    for (int i = 0; i < 20; ++i){
        printf("%d\n", data[i]);
    }
    // Sort  the  data
    sort(NUM_INTEGERS, data);
    //  Output  first 20  values
    printf("\nSorted\n");
    for (int i = 0; i < 20; ++i){
        printf("%d\n", data[i]);
    }
    return 0;
}