#pragma once

//structure to represent a student
struct student{
    unsigned int mat_no;
    char *name;
    char *address;
};

void printStudent(struct student s);
//declares that this will exist later on (in other file), not implementation