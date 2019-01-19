#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myfunctions.h"

struct student
{
    char name[50];
    int age;
    int mat_no;
};

int main()
{
    struct student s[30];
    printf("This program will allow you to enter student details up to 30 students, to finish enter a 0 at the prompt.\n");
    int i = 0;
    char buffer[50];
    int checkint;
    int sum = 0;
    for (i = 0; i < 30; i++)
    {

        printf("What is the students name?: \n");
        fgets(s[i].name, 50, stdin);

        printf("What is the students age?: \n");
        fgets(buffer, 50, stdin);
        s[i].age = atoi(buffer);

        printf("What is the students mat_no?: \n");
        fgets(buffer, 50, stdin);
        s[i].mat_no = atoi(buffer);

        removeNewLine(s[i].name);
        // printf("%s",s[i].name);
        // printf(", %d",s[i].age);
        // printf(", %d\n", s[i].mat_no);

        printf("Enter a new student? (1 to carry on, 0 to stop): \n");
        fgets(buffer, 50, stdin);
        removeNewLine(buffer);

        checkint = atoi(buffer);
        sum++;
        if (checkint == 0)
        {
            //print out all student records
            for (i = 0; i < sum; i++)
            {
                printf("%s %d %d\n", s[i].name, s[i].age, s[i].mat_no);
            }
            return 0;
        }
        else
        {
        }
    }
}