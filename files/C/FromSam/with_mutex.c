#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t xMutex;

long long int x = 0;

void writex(void * arg) //mutex prevents multiple threads accessing the values at the same time.
{
    for (int i = 0; i < 10000000; i++ ) {
        pthread_mutex_lock(&xMutex);
        x = x + 1;
        pthread_mutex_unlock(&xMutex);
    }
}

int main()
{
    printf("Hello world!\n");

    pthread_t t1[10];

    if (pthread_mutex_init(&xMutex, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

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
    pthread_mutex_destroy(&xMutex);
    return 0;
}
