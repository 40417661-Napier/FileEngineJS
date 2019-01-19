#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void removeNewLine(char name[])
{
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
    {
        name[len - 1] = '\0';
    }
}

typedef struct operation
{
    int encryptModeFlag; // checked pre-encryption
    int decryptModeFlag; // checked pre-encryption 
    int keyModeFlag; // checked pre-encryption/decryption for key value & validity
    int inputFlag; // checked pre-encryption/decryption for input medium
    int outputFlag; // checked pre-encryption/decryption for output medium
    int wipeFlag; // chekced post-encryption/decryption

    char iArgVal[1024]; // used pre-encryption/decryption for user input values <- file reading does not use this object
    char oArgVal[1024]; // written into for post-encryption/decryption for stdout of user inputted values only <- file output is handled in algorithm
    char k_ArgVal[1024]; // used pre-encryption/decryption

} operation;

operation mainStruct;

char *cyclerForNext(int size, char **src, char *finding)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(src[i], finding) == 0)
        {
            //finding val is found
            // return src[i + 1]; //returns the following argument
            //needs to interpret what its looking for, then interpret +1 and then set flags in the operation struct for the algorithm to use
            if (strcmp(finding, "-e") == 0)
            {
                mainStruct.encryptModeFlag = 1;
                //printf("Using Encryption!\n"); // Debugging
            }
            if (strcmp(finding, "-d") == 0)
            {
                mainStruct.decryptModeFlag = 1;
                //printf("Using Decryption!\n");
            }
            if (strcmp(finding, "-i") == 0)
            {
                //if i is size -1 it must be the last element, so accessing i+1 would cause a segmentation fault (biiig r.i.p) <- don't wanna do that.
                if (i == (size - 1))
                {
                    printf("No input file specified at the end of the call, please supply a filename while using the -i arg.\n");
                    exit(0);
                }
                if (src[i + 1][0] == '-' /* doesnt contain '-' for 1st char */)
                {
                    printf("An input file is needed if -i is invoked, please correct the arg.\n");
                    exit(0);
                }
                else
                {
                    strcpy(mainStruct.iArgVal, src[i + 1]);
                    //printf("Using input: %s\n", mainStruct.iArgVal);
                    // if inputFlag = 0 then it will ask for an input
                    mainStruct.inputFlag == 1;
                }
            }
            if (strcmp(finding, "-o") == 0)
            {
                if (i == (size - 1))
                {
                    printf("No output file specified at the end of the call, please supply a filename while using the -o arg.\n");
                    exit(0);
                }
                if (src[i + 1][0] == '-' /* doesnt contain '-' for 1st char */)
                {
                    printf("An output file is needed if -o is invoked, please correct the arg.\n");
                    exit(0);
                }
                else
                {
                    strcpy(mainStruct.oArgVal, src[i + 1]);
                    //printf("Using output: %s\n", mainStruct.oArgVal);
                    // if outputFlag = 0 then it will output to the cli
                    mainStruct.outputFlag == 1;
                }
            }
            if (strcmp(finding, "-k") == 0)
            {
                if (i == (size - 1))
                {
                    printf("No key specified at the end of the call, using 101 as default.\n");
                    strcpy(mainStruct.k_ArgVal, "101");
                    mainStruct.keyModeFlag = 1; // as the key has been set to 101
                    exit(0);
                }
                mainStruct.keyModeFlag = 1; // key has been set, needs validity checking in operationCheck()
                strcpy(mainStruct.k_ArgVal, src[i + 1]);
                //printf("Key: %s\n", mainStruct.k_ArgVal);
            }
            if (strcmp(finding, "-w") == 0)
            {
                //-w found
                mainStruct.wipeFlag = 1;
                //printf("Wiping file after encryption!");
            }
        }
    }
}

void operationCheck()
{ // doesn't need to be passed anything as all vars / struct are in the .h file
    //temporary output for debugging
    printf("decryptModeFlag: %d\n", mainStruct.decryptModeFlag);
    printf("encryptModeFlag: %d\n", mainStruct.encryptModeFlag);
    printf("iArgVal: %s\n", mainStruct.iArgVal);
    printf("inputFlag: %d\n", mainStruct.inputFlag);
    printf("k_ArgVal: %s\n", mainStruct.k_ArgVal);
    printf("keyModeFlag: %d\n", mainStruct.keyModeFlag);
    printf("oArgVal: %s\n", mainStruct.oArgVal);
    printf("outputFlag: %d\n", mainStruct.outputFlag);
    printf("wipeFlag: %d\n", mainStruct.wipeFlag);

}