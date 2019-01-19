#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// This is the function to be ran in another thread
void workFunction(void * arg)
{
    for (int i = 0; i < 10; i++) {
        printf("Entered work function\n");
        sleep(1);
        printf("Leaving work function\n");
    }
}

int main()
{
    // create a variable to manage a thread
    pthread_t thread1;

	// attach thread variable to the function we want to run as a thread
    if (pthread_create(&thread1, NULL, (void *)workFunction, NULL)) {
        printf("Error creating thread\n");
		return 1;
    }

	// do some work in the main thread (this thread)
    for (int i = 0; i < 10; i++) {
        printf("In main thread\n");
		sleep(1);
    }

	// wait for thread1 to finish
    if(pthread_join(thread1, NULL)) {
        printf("Error joining thread\n");
        return 2;
    }

    return 0;
}

