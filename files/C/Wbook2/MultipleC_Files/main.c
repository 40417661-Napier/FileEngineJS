#include "student.h"
#include <stdlib.h>

int main(int argc, char **argv){
    struct student s;
    s.mat_no = 40417661;
    s.name = "Niall A";
    s.address = "Napier";
    printStudent(s);
    return 0;
}