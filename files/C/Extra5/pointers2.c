#include <stdio.h>

#define SIZE_ARR 15

int length;

void printArray(int * data, int length) {
	// TODO implement me !!!
	for(int i = 0; i < length; i ++){
		printf("%d - %d",data[i], i);
		printf("\n");
	}
}

int main(void) {
	int myData[SIZE_ARR] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29};
	length = sizeof(myData)/sizeof(int);
	printArray(myData, length);

	return 0;
}
