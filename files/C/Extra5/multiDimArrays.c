// This program investigates two dimensional arrays, and how we can pass them
// into functions, and then use them into functions.
//
// This can be more difficult than expected, so often the sizes of arrays are
// defined as global constants. Note that func5 shows how we can avoid using global
// sizes, but is more complicated.

#include <stdio.h>

#define ROWS 4
#define COLS 3

int func1(int data_in[ROWS][COLS]) //passes predefined lengths for x and y
{
	printf("\nfunc 1 : ");
	for (int i = 0; i < ROWS; i++)
	{ //to not overflow on the rows
		for (int j = 0; j < COLS; j++)
		{ //to not overflow on the columns
			printf("%d ", data_in[i][j]); //printing row and column in entirety
		}
	}
}

int func2(int data_in[][COLS])
{
	printf("\nfunc 2 : ");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%d ", data_in[i][j]);
		}
	}
}

int func4(int *data_in)
{
	printf("\nfunc 4 : ");
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%d ", *(data_in + (i * COLS + j)));
		}
	}
}

int func5(int *data_in, int rows, int cols) //passing int for row and col <- not going to be flexible if array is changed in runtime, unless passed variables are re-evaluated
{
	printf("\nfunc 5 : ");
	for (int i = 0; i < rows; i++) //while i doesnt overflow on the passed variable
	{
		for (int j = 0; j < cols; j++) // while j doesnt overflow on the passed variable
		{
			printf("%d ", *(data_in + (i * cols + j)));
		}
	}
}

int main()
{
	int data[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}; //declaring array
	int data2[3][3] = {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}}; //declaring array
	printf("\nCalling functions with data array  ... \n");
	func1(data);
	func2(data);
	func4(&data[0][0]);
	func5(&data[0][0], ROWS, COLS);
	printf("\n\nCalling functions with data2 array  ... \n");
	//	func1(data2);   // can't call this correctly, as size of array is local to main
	//	func2(data2);	// can't call this correctly, as size of array is local to main
	//	func4(&data[0][0]);	// can't call this correctly, as size of array is local to main
	func5(data2[0], 3, 3);
	printf("\n\n");
	return 0;
}
