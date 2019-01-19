/*

Ask the user for the size of the array to be created, then using malloc, dynamically create an array of that size on the heap 
(note the array should be used to store integers). Loop through each item in the array reading in an integer from the user 
for each position. Print out the average value of all the values the user entered into the array.

*/

#include <stdio.h>
#include <stdlib.h>
#include "./myfunctions.h"

int main(int argc, char **argv)
{
    char buffer[15];
    printf("What size array do you want to create?: \n");
    fgets(buffer, 15, stdin);
    removeNewLine(buffer);
    // stores the length of the array to create in the heap.
    int toLoop = atoi(buffer); //stores the number from the char buffer to an int to use in a loop
    int *number = malloc(sizeof(int)*toLoop);
    int average = 0;
    //pointer for an int is the sizeof an int in the heap (4 bytes in heap reserved and is pointed to by number)
    // *toLoop is used so the chunk assigned in the heap wont result in unexpected behaviour in the case of an overlap
    // due to the heap not giving 4 excusive bytes, but 4 bytes within a chunk that can be large / smaller based on bin size

    for(int i = 0;i < toLoop;i++)
    {
        printf("Please enter a number to store in your array: \n");
        fgets(buffer, 15, stdin);
        int toAdd = atoi(buffer);
        number[i] = toAdd;
        average += toAdd;
    }
    for(int i = 0;i < toLoop;i++)
    {
        printf("%d, ", number[i]);
    }
    average = average / toLoop;
    printf("\n%d\n", average);
    return 0;
}
