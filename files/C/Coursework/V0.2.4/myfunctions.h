#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encryptionAlgorithm();
void decryptionAlgorithm();

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
    int keyModeFlag;     // checked pre-encryption/decryption for key value & validity
    int inputFlag;       // checked pre-encryption/decryption for input medium
    int outputFlag;      // checked pre-encryption/decryption for output medium
    int wipeFlag;        // chekced post-encryption/decryption
    int key;             // key used in algorithms (int derived from k_ArgVal)
    int keyFailFlag;     // used to show the inputted key is not of all digits

    char iArgValFile[1024];  // used to store the filename from arg -i
    char iArgValInput[1024]; // used to store the user input values <- file reading does not use this object
    char oArgVal[1024];      // written into for post-encryption/decryption for stdout of user inputted values only <- file output is handled in algorithm
    char k_ArgVal[1024];     // used pre-encryption/decryption

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
                    strcpy(mainStruct.iArgValFile, src[i + 1]);
                    //printf("Using input: %s\n", mainStruct.iArgVal);
                    // if inputFlag = 0 then it will ask for an input
                    mainStruct.inputFlag = 1;
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
                    mainStruct.outputFlag = 1;
                }
            }
            if (strcmp(finding, "-k") == 0)
            {
                if (i == (size - 1))
                {
                    printf("No key specified at the end of the call, using 101 as default.\n");
                    strcpy(mainStruct.k_ArgVal, "101");
                    mainStruct.keyModeFlag = 1; // as the key has been set to 101
                }
                else
                {
                    mainStruct.keyModeFlag = 1; // key has been set, needs validity checking in operationCheck()
                    strcpy(mainStruct.k_ArgVal, src[i + 1]);
                    //printf("Key: %s\n", mainStruct.k_ArgVal);
                }
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

    // //temporary output for debugging
    // printf("decryptModeFlag: %d\n", mainStruct.decryptModeFlag);
    // printf("encryptModeFlag: %d\n", mainStruct.encryptModeFlag);
    // printf("iArgVal: %s\n", mainStruct.iArgVal);
    // printf("inputFlag: %d\n", mainStruct.inputFlag);
    // printf("k_ArgVal: %s\n", mainStruct.k_ArgVal);
    // printf("keyModeFlag: %d\n", mainStruct.keyModeFlag);
    // printf("oArgVal: %s\n", mainStruct.oArgVal);
    // printf("outputFlag: %d\n", mainStruct.outputFlag);
    // printf("wipeFlag: %d\n", mainStruct.wipeFlag);
    if (mainStruct.inputFlag == 0)
    {
        // needs to default to stdin reading
        printf("Please Enter Text For Encryption (1024 size max): ");
        fgets(mainStruct.iArgValInput, 1024, stdin);
        removeNewLine(mainStruct.iArgValInput);
    }
    if (mainStruct.keyModeFlag == 0)
    {
        strcpy(mainStruct.k_ArgVal, "101");
        // sets default key
        mainStruct.keyModeFlag = 1;
        mainStruct.key = 101;
        // sets flag to true
        printf("Using 101 default key\n");
    }
    else
    {
        removeNewLine(mainStruct.k_ArgVal);

        if (mainStruct.keyFailFlag == 1)
        {
            //failed
            printf("They key you have entered has a non integer value, setting key as 101\n");
            mainStruct.key = 101;
        }
        else
        {
            mainStruct.key = atoi(mainStruct.k_ArgVal);
            // set int key as user input
            if (mainStruct.key > 127 || mainStruct.key < 1)
            {
                printf("Key is outside range (1-127), setting as 101");
                mainStruct.key = 101;
            }
            //printf("Set key as %d\n", mainStruct.key);
        }
    }
    if (mainStruct.encryptModeFlag == 1)
    {
        encryptionAlgorithm();
    }
    else
    {
        decryptionAlgorithm();
    }
}

void encryptionAlgorithm()
{
    /* For encryption, the program should use the following basic algorithm:
    1. set k based on user input, else to default value 101
    2. convert each character to an int
    3. xor the int value of each character with k
    4. bitshift each value left by 2
    5. convert each int character to a hex character string with spaces between each value */

    if (mainStruct.inputFlag == 0)
    {
        // reading from stdin -> mainStruct.iArgValInput[1024]
        char temp[1024];
        int buffer[1024];
        int k = mainStruct.key;
        unsigned int result = 0;

        strcpy(temp, mainStruct.iArgValInput);

        removeNewLine(temp);
        int i = 0;
        for (i = 0; i < strlen(temp) + 1; i++)
        {
            //printf("%d\n", temp[i]);
            buffer[i] = temp[i] ^ k;
            buffer[i] <<= 2;
            if (mainStruct.outputFlag == 1)
            {
                FILE *myFileWritePlus; // varibale to write and update the output file <- discards previous contents
                if ((myFileWritePlus = fopen(mainStruct.oArgVal, "a")))
                { // check if file exists (if not, create)
                    // open file

                    fprintf(myFileWritePlus, "%04x ", buffer[i]);
                    // appent part to file

                    fclose(myFileWritePlus);
                    // close file
                }
                else
                {
                    //file doesnt exist
                    //create file
                    FILE *createdFile;
                    createdFile = fopen(mainStruct.oArgVal, "w");
                    fclose(createdFile);
                    myFileWritePlus = fopen(mainStruct.oArgVal, "a");
                    fprintf(myFileWritePlus, "%04x ", buffer[i]);
                    // appent part to file

                    fclose(myFileWritePlus);
                    // close file
                }
            }
            else
            {
                // output to stdout
                printf("%04x ", buffer[i]);
            }
        }
        printf("\n");
    }

    else
    {
        /* reading from file -> mainStruct.iArgValFile[1024]
        check if file exists, if false - exit, if true - continue
        
        read from file and store in buffer
        same as above algorithm
        
        */

        FILE *myFileRead; // varibale to read an input file
        if ((myFileRead = fopen(mainStruct.iArgValFile, "rb")))
        {
            // check if file exists (if not, end)
            // opened file
            // for each part of the file, read all bytes to buffer in heap and then encrypt

            char *source;
            long bufferSize;
            if (myFileRead != NULL)
            {
                if (fseek(myFileRead, 0, SEEK_END) == 0)
                {
                    bufferSize = ftell(myFileRead);
                    //printf("%ld\n", bufferSize);
                    if (bufferSize == -1)
                    { /* Error */
                    }
                    source = malloc(sizeof(char) * (bufferSize + 1));
                    /* Go back to the start of the file. */
                    if (fseek(myFileRead, 0, SEEK_SET) != 0)
                    { /* Error */
                    }

                    /* Read the entire file into memory. */
                    size_t newLen = fread(source, sizeof(char), bufferSize, myFileRead);
                    if (ferror(myFileRead) != 0)
                    {
                        fputs("Error reading file", stderr);
                    }
                    else
                    {
                        source[newLen++] = '\0'; // Just to be safe.
                    }
                }
                fclose(myFileRead);
            }

            //printf("%s\n", source); // debugging

            // now encrypt from source and write to output if needed

            int *buffer = malloc(sizeof(int) * (bufferSize + 1));
            int k = mainStruct.key;
            unsigned int result = 0;

            long i = 0;
            for (i = 0; i < strlen(source) + 1; i++)
            {
                //printf("%d\n", temp[i]);
                buffer[i] = source[i] ^ k;
                buffer[i] <<= 2;
                if (mainStruct.outputFlag == 1)
                {
                    FILE *myFileWritePlus; // varibale to write and update the output file <- discards previous contents
                    if ((myFileWritePlus = fopen(mainStruct.oArgVal, "a")))
                    { // check if file exists (if not, create)
                        // open file

                        fprintf(myFileWritePlus, "%04x ", buffer[i]);
                        // appent part to file

                        fclose(myFileWritePlus);
                        // close file
                    }
                    else
                    {
                        //file doesnt exist
                        //create file
                        FILE *createdFile;
                        createdFile = fopen(mainStruct.oArgVal, "w");
                        fclose(createdFile);
                        myFileWritePlus = fopen(mainStruct.oArgVal, "a");
                        fprintf(myFileWritePlus, "%04x ", buffer[i]);
                        // appent part to file

                        fclose(myFileWritePlus);
                        // close file
                    }
                }
                else
                {
                    // output to stdout
                    printf("%04x ", buffer[i]);
                }
            }
            printf("\n");

            free(source); /* Free heap space since its no longer needed */
            //close file
            fclose(myFileRead);
        }
        else
        {
            //file doesnt exist
            printf("The file specified doesn't exist, please try again.\n");
            exit(0);
        }
    }
}

void decryptionAlgorithm()
{
    // if -i was supplied
    if (mainStruct.inputFlag == 1)
    {
        FILE *myFileRead;
        // check if input file exists
        if (myFileRead = fopen(mainStruct.iArgValFile, "r"))
        {
            // reading the user supplied file
            // need to get length for the loop
            fseek(myFileRead, 0, SEEK_END);
            int length = ftell(myFileRead) + 50;
            fseek(myFileRead, 0, SEEK_SET);
            char buffer[length]; // array the size of the file, can be malloc'd in the future
            // memset(buffer, '\0', length);
            memset(buffer, '\0', length);
            fread(buffer, length, 1, myFileRead);
            // stored the file input into the buffer variable
            //printf("%s\n", buffer);
            // need to now traverse the buffer variable, reading 5 characters, then using the first 4
            for (int i = 0; i < strlen(buffer); i += 5)
            {
                // break will leave the loop
                if (i + 5 > strlen(buffer))
                {
                    break;
                }
                else
                {
                    char tempStorage[4];
                    strncpy(tempStorage, buffer + i, 4);
                    // printf("%s ", tempStorage);
                    // convert the 4 chars to denary from hex (asuming hex) ->
                    unsigned int num;
                    // Location in string to read from next
                    char *next = tempStorage;
                    mainStruct.key = atoi(mainStruct.k_ArgVal);

                    num = strtol(next, &next, 16);
                    //printf("%d", num[i]);
                    // bit shitf >> 2
                    num >>= 2;
                    //printf("%d", num[i]);
                    num = num ^ mainStruct.key;
                    // convert to ascii

                    if (mainStruct.outputFlag == 1)
                    {
                        // output to file (append)
                        FILE *myFileWrite;
                        if (myFileWrite = fopen(mainStruct.oArgVal, "a"))
                        {
                            //file exists
                            fprintf(myFileWrite, "%c", num);
                            fclose(myFileWrite);
                        }
                        else
                        {
                            // file doesnt exist
                            char command[99] = "touch ";
                            strcat(command, mainStruct.oArgVal);
                            system(command);
                            // creates file for next iteration
                        }
                    }
                    else
                    {
                        // no output specified
                        printf("%c", num);
                    }
                }
            }
        }
        else
        {
            printf("Input file does not exist, please try again with correct arguments.\n");
        }
    }
    else
    {
        // if -i was not supplied
        // read from stdin
        // do the same as above

        // reading the mainStruct.iArgValInput variable
        // need to get length for the loop

        int length = strlen(mainStruct.iArgValInput);
        char buffer[length]; // array the size of the file, can be malloc'd in the future

        memset(buffer, '\0', length);

        strcpy(buffer, mainStruct.iArgValInput);
        //fread(buffer, length, 1, mainStruct.iArgValInput);
        // stored the arg input into the buffer variable

        // need to now traverse the buffer variable, reading 5 characters, then using the first 4
        for (int i = 0; i < strlen(buffer); i += 5)
        {
            // break will leave the loop
            if (i + 5 > strlen(buffer))
            {
                break;
            }
            else
            {
                char tempStorage[4];
                strncpy(tempStorage, buffer + i, 4);
                // printf("%s ", tempStorage);
                // convert the 4 chars to denary from hex (asuming hex) ->
                unsigned int num;
                // Location in string to read from next
                char *next = tempStorage;
                mainStruct.key = atoi(mainStruct.k_ArgVal);

                num = strtol(next, &next, 16);
                num >>= 2;
                num = num ^ mainStruct.key;

                if (mainStruct.outputFlag == 1)
                {
                    // output to file (append)
                    FILE *myFileWrite;
                    if (myFileWrite = fopen(mainStruct.oArgVal, "a"))
                    {
                        //file exists
                        fprintf(myFileWrite, "%c", num);
                        fclose(myFileWrite);
                    }
                    else
                    {
                        // file doesnt exist
                        char command[99] = "touch ";
                        strcat(command, mainStruct.oArgVal);
                        system(command);
                        // creates file for next iteration
                    }
                }
                else
                {
                    // no output specified
                    printf("%c", num);
                }
            }
        }
    }
    printf("\n");
}

void wipeFile()
{
    // get length of file
    FILE *readLength;
    if ((readLength = fopen(mainStruct.iArgValFile, "r")))
    {
        //file exists
        fseek(readLength, 0, SEEK_END);
        // allocate heap
        long bufferSize = ftell(readLength);
        fseek(readLength, 0, SEEK_SET);
        fclose(readLength);
        if (bufferSize == -1)
        { /* Error */
        }

        int i = 0;
        srand(time(NULL));

        FILE *rewriteFile = fopen(mainStruct.iArgValFile, "w");
        fprintf(rewriteFile, " ");
        fclose(rewriteFile);
        rewriteFile = fopen(mainStruct.iArgValFile, "a");
        for (i = 0; i < bufferSize; i++)
        {
            printf("%d\n ", (0 + rand() % 10));
            // write to file
            fprintf(rewriteFile, "%d", (0 + rand() % 10));
        }
        fclose(rewriteFile);

        // delete file
        int removeFile = remove(mainStruct.iArgValFile);
    }else{
        printf("File doesn't exist! Will not wipe.\n");
    }
}
