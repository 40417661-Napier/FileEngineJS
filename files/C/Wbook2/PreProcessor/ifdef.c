#include <stdio.h>

int main(int argc, char **argv){
    #ifdef DEBUG
        printf("I'm in Debug Mode!\n");
    #elif RELEASE
        printf("I'm In Release Mode!\n");
    #else
        printf("What Mode Am I In?\n");
    #endif  
        return 0;
}
