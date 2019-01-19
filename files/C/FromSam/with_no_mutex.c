#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

long long int x = 0;

void writex(void * arg) //error occurs as there is no mutex locking the values as more than one thread is accessing the func at the same time.
{
    for (int i = 0; i < 10000000; i++ ) {
        x = x + 1;
    }
}

int main()
{
    printf("Hello world!\n");

    pthread_t t1[10];

    for(int i = 0; i < 10; i++) {
        if(pthread_create(&t1[i], NULL, (void *)writex, NULL)) {
            printf("Error creating thread\n");
            return 1;
        }
    }

    for(int i = 0; i < 10; i++) {
        if(pthread_join(t1[i], NULL)) {
            printf("Error joining thread\n");
            return 2;
        }
    }

    printf("x is %lld\n", x);
    return 0;
}
