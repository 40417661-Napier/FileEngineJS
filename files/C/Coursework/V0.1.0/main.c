#include "myfunctions.h"

/*
-----MyCrypt V0.1.0-----
0.0 Requirements
1.Layout of requirements for project

0.1 Requirements
1. Function shells built
2. Read command line arguments

0.2 Requirements
3. Interpret command line arguments
4. If the application is invoked with no arguments, a brief help message should be output and the application should terminate.

0.3 Requirements
2. If no input filename is provided then the application should read from stdin & store in temp variable
3. If no output filename is provided then the application should write to stdout

0.4 Requirements
1. Encryption Algorithm [brief in function]
2. The application should default to the encryption function if no parameter is given to indicate otherwise
3. If a key is provided outwith the range 1 … CHAR_MAX, the application should use the default value of 101, and issue an appropriate warning.
3. If no key is defined then the basic algorithm function should be used with a default key value of 101.

0.5 Requirements
1. Decryption Algorithm
2. Wiping Function 

0.6 Requirements
1. Error handling
2. Temp Cleanup if necesary

0.7 Requirements
1. Code hardening
2. Testing & documentation

0.8 Requirements
1. Makefile creation
2. Testing & documentation

Considerations:
- good choice of variable and function names, layout, clarity, and use of comments
- appropriate use of C features – eg struct and enum types for modal operation and file handling
- memory management – eg using a buffer to reduce read/write operations
- breadth of testing and management of testing – eg definition of test scenarios and use of makefiles


-- Argument Rundown --
-e           |  Indicates that encryption should occur
-d           |  Indicates that decryption should occur
-i filename  |  Indicates the input file name
-o filename  |  Indicates the output file name
-k key       |  A key value passed to the algorithm for use
-w           |  Indicates that input file should be wiped after encryption; valid only with -e

*/

