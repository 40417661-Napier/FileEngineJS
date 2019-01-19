#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"

int main(int argc,char **argv)
{
    FILE *myFileRead = fopen("readText.txt", "r"); //varibale to read
    FILE *myFileWrite = fopen("readText.txt", "w"); //varibale to write
    FILE *myFileAppend = fopen("readText.txt", "a"); //varibale to append
    FILE *myFileReadPlus = fopen("readText.txt", "r+"); //varibale to read and update
    FILE *myFileWritePlus = fopen("readText.txt", "w+"); //varibale to write and updating -> discards any existing content
    FILE *myFileAppendPlus = fopen("readText.txt", "a+"); //varibale to read and update at the end -> doesnt discard existing content
    FILE *myFileReadBinary = fopen("readText.txt", "b"); //varibale to read in binary
    
    FILE *toUse = fopen("readText.txt", "rb"); // variable to read in binary
}
