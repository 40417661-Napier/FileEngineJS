#include "search.h"

int search(int value, int size, int *data){
    for(int i = 0; i < size; i++){
        if(data[i] == value){
            //found
            return i; //returns the element where found
        }
    }
    return -1; //not found, return -1
}