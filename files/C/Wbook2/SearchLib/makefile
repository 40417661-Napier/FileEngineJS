buildLib:
	gcc -std=c99 -c search.c sort.c generate.c
	ar rcs  libarray.a search.o sort.o generate.o
	gcc -std=c99  test.c -L. -larray