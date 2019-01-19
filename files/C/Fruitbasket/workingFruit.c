#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUMOFFRUITS 5

// my node for a linked list, contains string, quantity and pointer to next node
typedef struct fruitBasket {
    char fruittype[15];
    int qty;
    struct fruitBasket *next;
} fruitBasket;

// possible fruit types
char fruit[NUMOFFRUITS][14] = {"bananas", "pairs", "apples", "oranges", "lemons"};

// total of fruit unloaded
int totalUnloaded = 0;

// head and tail pointer for linked list
fruitBasket * head = NULL, * tail = NULL;

// function prototypes to define interface to my fruitbasket list
fruitBasket * makeBasket(void);
void loadBasket(void);
void unloadBasket(void);
void checkQueue(void);
void testFruit(void);

int main()
{
    srand(time(NULL));
    testFruit();
    return 0;
}

fruitBasket * makeBasket(void)
{
    // dynamically create a new fruitbasket and assign its data
    fruitBasket * newbasket = (fruitBasket *) malloc(sizeof(fruitBasket));
    strcpy(newbasket->fruittype, fruit[rand()%NUMOFFRUITS]);
    newbasket->qty = (rand() % 20) + 1;
    newbasket->next = NULL;
    // return copy of pointer to new fruitbasket
    return newbasket;
}

void loadBasket(void)
{
    fruitBasket * newBasket = makeBasket();
    // if its first element tell head to point to it
    if (head == NULL) {
       head = newBasket;
    } else {
         // make temporary pointer which will traverse list
        fruitBasket * tempPtr = head;
        // iterate through list until we are at last element
        while (tempPtr->next != NULL){
            tempPtr = tempPtr->next;
        }
        // when we are at last element assign next to be our new fruitbasket
        tempPtr->next = newBasket;
    }
}

void unloadBasket(void)
{
    // check list isnt empty
    if (head != NULL) {
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
    if (head != NULL) {
        int tot = 0, num  = 0;
        fruitBasket *tempPtr = head;
        // do this while loop while we have a valid element in the list
        while (tempPtr != NULL)
        {
            num++;
            tot += tempPtr->qty;
            // assign tempPtr to point to next item in list
            tempPtr = tempPtr-> next;
        }
        printf("Queue contains %d items and %d kilos of fruit\n", num, tot);
    }
	else
		printf("Queue is empty\n");
}

void testFruit(void)
{
    // call other functions in this function to test list
    checkQueue();
    loadBasket();
    loadBasket();
    loadBasket();
    checkQueue();
    unloadBasket();
    checkQueue();
}


