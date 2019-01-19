#include <stdio.h>

#define COLS 3
#define ROWS 4

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

int main()
{
    int data[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int data2[3][3] = {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}};
    printf("\nCalling functions with data array ... \n");
    func1(data);
    printf("\n\n");
    return 0;
}