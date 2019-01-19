#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexB = PTHREAD_MUTEX_INITIALIZER;

void workFunctionA(void * arg)
{
    for (int i = 0; i < 10000; i++ ) {
		printf("A :: Locking mutexA\n");
        pthread_mutex_lock(&mutexA);
		printf("A :: mutexA locked\n");
		//sleep(1);
        printf("A :: Locking mutexB\n");
        pthread_mutex_lock(&mutexB);
		printf("A :: mutexB locked\n");
		//sleep(1);
		printf("A :: releasing mutexes\n");
		pthread_mutex_unlock(&mutexA);
		pthread_mutex_unlock(&mutexB);	
    }
}

void workFunctionB(void * arg)
{
    for (int i = 0; i < 10000; i++ ) {
		printf("B :: Locking mutexB\n");
        pthread_mutex_lock(&mutexB);
		printf("B :: mutexB locked\n");
		//sleep(1);
        printf("B :: Locking mutexA\n");
        pthread_mutex_lock(&mutexA);
		printf("B :: mutexB locked\n");
		//sleep(1);
		printf("B :: releasing mutexes\n");
		pthread_mutex_unlock(&mutexA);
		pthread_mutex_unlock(&mutexB);	
    }
}

int main()
{
    printf("Hello world!\n");

    pthread_t thread1, thread2;


	if(pthread_create(&thread1, NULL, (void *)workFunctionA, NULL)) {
		printf("Error creating thread1\n");
		return 1;
	}
	if(pthread_create(&thread2, NULL, (void *)workFunctionB, NULL)) {
		printf("Error creating thread2\n");
		return 1;
	}

	if(pthread_join(thread1, NULL)) {
		printf("Error joining thread1\n");
		return 2;
    }
	if(pthread_join(thread2, NULL)) {
		printf("Error joining thread1\n");
		return 2;
    }

    pthread_mutex_destroy(&mutexA);
	pthread_mutex_destroy(&mutexB);
    return 0;
}
