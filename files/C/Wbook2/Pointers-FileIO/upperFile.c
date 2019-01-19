// Write a program that asks the user for a file to read, then asks the user for a file to write. 
// It should then write the contents of the input file to the output file but in uppercase  
// Hint, look at using the toupper function from ctype.h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "myfunctions.h"

#define CHARSIZE 1024

char buffer[CHARSIZE];
char file[CHARSIZE];
char upperWrite[CHARSIZE];
int counter;
char filePath[CHARSIZE];

int main(){
    
    printf("Please Enter A File To Read: \n");
    fgets(file, 500, stdin);
    removeNewLine(file);
    printf("Please Enter A File To Write To: \n");
    fgets(upperWrite, 500, stdin);
    removeNewLine(upperWrite);
    strcpy(filePath, file);
    FILE * infile = fopen(filePath, "r");
    FILE * outfile = fopen(upperWrite, "w");

    if (infile) { //while not 0 <- becomes 0 at the end of the filestream
        int indata;
        while ((indata = fgetc(infile)) != EOF) { //while indata is equal to data fetched from infile which doesn't equal the end of file marker
            //printf("%c",toupper((char)indata)); //print line debug
            fputc((toupper((char)indata)), outfile); //write to file
        }
        printf("\n");
        fclose(infile); //close file
    }
}