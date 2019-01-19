#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_BUF_SIZE 50 //replaces every instance of NAME_BUFF_SIZE with 50

int main()
{
    char newname[NAME_BUF_SIZE]; //creates char array

    FILE * infile = fopen("datafile.txt", "r"); //read mode for datafile.txt
    if (infile) { //while not 0 <- becomes 0 at the end of the filestream
        int indata;
        while ((indata = fgetc(infile)) != EOF) { //while indata is equal to data fetched from infile which doesn't equal the end of file marker
            printf("%c", (char)indata); //print line
        }
        fclose(infile); //close file
    }

    FILE * outfile = fopen("datafile.txt", "a"); //append mode to write to datafile.txt
    if (outfile) { //while outfile != 0
        printf("Enter new name for file : "); //prompt for user input
        fgets(newname, NAME_BUF_SIZE, stdin); //get newname, size defined at top of file, using standard input
        for (int i = 0; i < strlen(newname); i++) { //for loop length of input
            fputc((int)newname[i], outfile); //append to file
        }
        fclose(outfile); //close file
    }

    return 0;
}
