#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/* 
    /gcc -o ConcurrentFruit workingFruit.c -lpthread
*/

#define NUMOFFRUITS 5
int continuing = 1;
int i = 0;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;
// possible fruit types
char fruit[NUMOFFRUITS][14] = {"bananas", "pairs", "apples", "oranges", "lemons"};
// total of fruit unloaded
int totalUnloaded = 0;

// my node for a linked list, contains string, quantity and pointer to next node
typedef struct fruitBasket
{
    char fruittype[15];
    int qty;
    struct fruitBasket *next;
} fruitBasket;

// function prototypes to define interface to my fruitbasket list
fruitBasket *makeBasket(void);
void loadBasket(void);
void unloadBasket(void);
void checkQueue(void);
void testFruit(void);

int sleeper(void *arg)
{
    sleep(60);
    continuing = 0;
}

int keepchecking(void *arg)
{
    sleep(1);
    checkQueue();
}

int keepunloading(void *arg)
{
    while (continuing == 1)
    {
        if (i > 3)
        {
            sleep(3);
            pthread_mutex_lock(&qlock);

            unloadBasket();

            pthread_mutex_unlock(&qlock);
        }
        else
        {
            sleep(3);
            i++;
        }
    }
}

int keeploading(void *arg)
{
    while (continuing == 1)
    {
        sleep(3);
        pthread_mutex_lock(&qlock);
        loadBasket();
        pthread_mutex_unlock(&qlock);
    }
}

// head and tail pointer for linked list
fruitBasket *head = NULL, *tail = NULL;

fruitBasket *makeBasket(void)
{
    // dynamically create a new fruitbasket and assign its data
    fruitBasket *newbasket = (fruitBasket *)malloc(sizeof(fruitBasket));
    strcpy(newbasket->fruittype, fruit[rand() % NUMOFFRUITS]);
    newbasket->qty = (rand() % 20) + 1;
    newbasket->next = NULL;
    // return copy of pointer to new fruitbasket
    return newbasket;
}

void loadBasket(void)
{
    fruitBasket *newBasket = makeBasket();
    printf("loading %d kg of %s\n", newBasket->qty, newBasket->fruittype);
    // if its first element tell head to point to it
    if (head == NULL)
    {
        head = newBasket;
    }
    else
    {
        // make temporary pointer which will traverse list
        fruitBasket *tempPtr = head;

        // iterate through list until we are at last element
        while (tempPtr->next != NULL)
        {
            tempPtr = tempPtr->next;
        }
        // when we are at last element assign next to be our new fruitbasket
        tempPtr->next = newBasket;
    }
}

void unloadBasket(void)
{
    // check list isnt empty
    if (head != NULL)
    {
        fruitBasket *tempPtr;
        tempPtr = head;
        printf("unloading %d kg of %s\n", tempPtr->qty, tempPtr->fruittype);
        totalUnloaded += tempPtr->qty;
        // assign head to be 2nd element in list
        head = head->next;
        // delete old first element of list
        free(tempPtr);
    }
    else
        printf("nothing to unload at present\n");
}

void checkQueue(void)
{
    // check if list is empty
    if (head != NULL)
    {
        int tot = 0, num = 0;
        fruitBasket *tempPtr = head;
        // do this while loop while we have a valid element in the list
        while (tempPtr != NULL)
        {
            num++;
            tot += tempPtr->qty;
            // assign tempPtr to point to next item in list
            tempPtr = tempPtr->next;
        }
        printf("Queue contains %d items and %d kilos of fruit\n", num, tot);
    }
    else
        printf("Queue is empty\n");
}

int main()
{
    srand(time(NULL));
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    pthread_create(&t1, NULL, (void *)sleeper, NULL);
    pthread_create(&t2, NULL, (void *)keeploading, NULL);
    pthread_create(&t3, NULL, (void *)keepunloading, NULL);
    pthread_create(&t4, NULL, (void *)keepchecking, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    return 0;
}