#include "myfunctions.h"
/*
-----MyCrypt V0.2.1-----
Requirements
1. Analyse arguments and ensure defaults are set if necessary
2. Check key validity

*/

int main(int argc, char **argv)
{

    // calling the cycleForNext function to find what args were used, and where appropriate
    // what the following arguments were (for -i, -o, -k)

    // checking what mode to operate in, if not found will default to encrypt
    cyclerForNext(argc, argv, "-e");
    cyclerForNext(argc, argv, "-d");

    if (mainStruct.encryptModeFlag == 1)
    {
        if (mainStruct.decryptModeFlag == 1)
        {
            printf("Cannot use both -e and -d args, please use valid args.\n");
            exit(0);
        }
    }
    if (mainStruct.encryptModeFlag == 0)
    {
        if (mainStruct.decryptModeFlag == 0)
        {
            printf("Defaulting to encryption.\n");
            mainStruct.encryptModeFlag = 1;
        }
    }

    cyclerForNext(argc, argv, "-i"); // finds argument after -i
    cyclerForNext(argc, argv, "-o"); // finds argument after -o
    cyclerForNext(argc, argv, "-k"); // finds argument after -k
    cyclerForNext(argc, argv, "-w"); // finds if -w was called

    // run algorithm final checks
    operationCheck();

    // call appropriate function passing the struct for above info
}
