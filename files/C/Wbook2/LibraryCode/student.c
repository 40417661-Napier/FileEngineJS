#include "student.h"
#include <stdio.h>

void printStudent(struct student s){
    printf("Matric: %d\n", s.mat_no);
    printf("Student Name: %s\n", s.name);
    printf("Student Address: %s\n", s.address);
}