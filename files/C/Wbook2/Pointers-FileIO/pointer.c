#include <stdio.h>
#include <stdlib.h>

void pointerPass(int *y){ //knows it is passed a pointer to an int (4 bytes till stop)
    printf("Address of x in function = %p\n", y);
    //above relays address of variable y in memory
    //below relays value stored in memory address of y, which is variable x in main
    printf("Value at start of function = %d\n", *y);

    *y = 20; //changes the value of the variable stored in memory address x

    printf("Value at end of function = %d\n", *y);
    printf("Address of x at end of function = %p\n", y);
}    

int main(int argc, char ** argv){
    int x = 10;
    printf("Start address of x = %p\n", &x);
    printf("Before function call, x = %d\n", x);
    pointerPass(&x);//passes the address of variable x
    printf("After function call, x = %d\n", x);
    printf("End address of x = %p\n", &x);
    return 0;
}

