//To be finished!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfunctions.h"

//define in case I need to change across the whole program quickly
#define BUFFER_LEN 50

//declare used variables
int lowEndLower = 97;
int highEndLower = 122;
int lowEndHigher = 65;
int highEndHigher = 90;
char direction[BUFFER_LEN];
char buffer[BUFFER_LEN];
char cipherBuffer[BUFFER_LEN];
char tempStorage[BUFFER_LEN];

void main(){
    printf("Enter Secret Message: \n");
    fgets(buffer, BUFFER_LEN, stdin);
    printf("(L)eft or (R)ight?: \n");
    fgets(direction, BUFFER_LEN, stdin);
    removeNewLine(buffer); //remove the \n and place \0 at the end of the char array
    removeNewLine(direction); //remove the \n and place \0 at the end of the char array
    //for loop through the array
    for(int i = 0; i < strlen(buffer) - 1; i++){
        strcpy(tempStorage[i], buffer[i]);
        //need to fix the strcpy error
        //add five to ascii val stored in tempStorage to write to cipherBuffer
        //check the direction to cipher to

        strcpy(cipherBuffer[i], tempStorage);
    }
}

void goLeft(){

}

void goRight(){

}