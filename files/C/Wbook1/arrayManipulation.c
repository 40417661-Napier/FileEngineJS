#include <stdio.h>
int main(){
  int array[8];
  int x;
  char* temp;
  
  for(x=0; x<8; x++)
    
    array[x] = x;
  
  for(x=0; x<8; x++)
    printf("%d", array[x]);

  printf("\n");
  return 0;
}   