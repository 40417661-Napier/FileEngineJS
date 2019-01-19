#include <stdio.h>


int main(void) {
	int x = 10;
	int *x_ptr = &x;

	printf("The value of x is %d, the address of x is %p \n", x, x_ptr);
	printf("The value of x_ptr is %p, the value returned derefrencing x_ptr is %d \n", x_ptr, *x_ptr);

	return 0;
}
