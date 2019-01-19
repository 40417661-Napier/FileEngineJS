#include <stdio.h>

int main(void) {
	char name[20] = "Schwarzenegger"; //creates char array for the name Schwarzenegger

	char * name_ptr = name; //pointer to the variable name (holds the address of the starting element of name)

	while(*name_ptr) { //while value of the name_ptr is "correct"
		printf("%c\n", *name_ptr); //print out each element 
		name_ptr += 1; //increment pointer by 1
	}

	return 0; //exit
}