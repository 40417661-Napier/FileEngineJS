main:
	gcc -c student.c main.c student.c
	ar rcs libstudent.a main.o
	gcc main.o student.o -L. -lstudent
