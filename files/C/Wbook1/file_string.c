#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 500 //replaces instances with 500
#define NAME_BUF_SIZE 50 //replaces instances with 50
//replaces every instance making it easier to update across whole program

int main()
{
    char buffer[BUF_SIZE];
    char newname[NAME_BUF_SIZE];
    //variable decleration

    FILE * infile = fopen("datafile.txt", "r"); //open in read mode the datafile.txt
    if (infile) { //while != 0
        while (fgets(buffer, BUF_SIZE, infile)) { //load string from infile (datafile.txt) into char buffer
            printf("%s", buffer); //output buffer
        }
        fclose(infile); //close file
    }

    FILE * outfile = fopen("datafile.txt", "a"); //open in append mode
    if (outfile) { //while != 0
        printf("Enter new name for file : "); //prompt for user input
        fgets(newname, NAME_BUF_SIZE, stdin); //read from input, load into newname using standard input
        fputs(newname, outfile); //append to file
        fclose(outfile); //close file
    }

    return 0; //exit
}
