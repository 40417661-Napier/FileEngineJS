// file SIZES.c
//=============
#include <stdio.h>
// handy function to return size of an array of longs
long int getsize(long int x[])
{
return sizeof(x);
}
int main()
{
long my_array[] = {1,2,3,4,5,6,7,8,9,10};
printf("the size of my_array is %d\n", sizeof(my_array));
// great, it works, now I'll use the handy getsize function
printf("the size of my_array is %d\n", getsize(my_array));
return 0;
}