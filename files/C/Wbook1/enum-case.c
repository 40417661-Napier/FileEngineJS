#include "myfunctions.h"
struct student{
    char name[50]; int age; int mat_no;};
enum choice{
    EXIT = 0, restart = 1};
int main(){
    struct student s[1]; int flag =1; while(flag){
        char buffer[50]; printf("This program will allow you to enter a students' details.\nEnter 1 to add a new student\nEnter 0 to quit\n"); fgets(buffer, 50, stdin);
        enum choice ch = atoi(buffer); switch(ch){
            case EXIT:
                printf("Exiting\n"); flag = 0; break;
            case restart:
                printf("Overwriting current\nWhat is the students name?: \n"); fgets(s[0].name, 50, stdin); printf("What is the students age?: \n"); fgets(buffer, 50, stdin); s[0].age = atoi(buffer); printf("What is the students mat_no?: \n"); fgets(buffer, 50, stdin); s[0].mat_no = atoi(buffer); removeNewLine(s[0].name); printf("%s, %d, %d\n",s[0].name, s[0].age, s[0].mat_no); break;
            default:
                printf("Not a valid input!\n");}}return 0;}