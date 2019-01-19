#include "sort.h"
#include <stdio.h>

//bubble sort
int i;
int j;
int buffer;

void sort(int size, int *data){
    for (j = 0; j < size; ++j){
        for (i = 0; i < size  - (j + 1); i++){
            if (data[i] > data[i + 1]){
                buffer = data[i + 1];
                data[i + 1] = data[i];
                data[i] = buffer;
            }
        }
        if(j % 1000 == 0){
            printf("%.2f%% sorted \n", (( float)j / (float)size) * 100.0f);
        }
    }
    for(i = 0; i < size; i++){
        printf("%d, ", data[i]);
    }printf("\n");
}

// int main(int argc, char **argv[]){
   
//     int data[50];
//     for(int i = 0; i < 50; i++){
//         data[i] = 50 - i;
//     }

//     sort(50,data);
// }
