#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"

void main(int argc, char **argv){
    //variable setup
    char buffer[10];
    float hourly;
    float daily;
    float weekly;
    float monthly;
    float yearly;
    
    if(argc < 2){
        // outdated, using args by default but if none detected will use prompt
        printf("Enter hourly rate: ");
        fgets(buffer, 10, stdin); //stores user input in the buffer variable to be converted
        removeNewLine(buffer); //removes the new line char from the buffer variable for easy conversions
    }else{
        strcpy(buffer, argv[1]); //copy straight from the argument into buffer to be converted
    }

    hourly = atof(buffer); //stores the user input in the float variable to be used for calculations

    //calculations [assuming 8 hr day, 5 day week, 4 week month and 12 month year]
    daily = hourly * 8;
    weekly = daily * 5;
    monthly = weekly * 4;
    yearly = monthly * 12;

    printf("%.2f daily\n", daily);
    printf("%.2f weekly\n", weekly);
    printf("%.2f monthly\n", monthly);
    printf("%.2f yearly\n", yearly);
}