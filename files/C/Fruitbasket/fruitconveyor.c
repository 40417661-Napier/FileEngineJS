#include "myfunctions.h"

typedef struct FruitBasket
{
    char fruittype[15];
    int qty;
    struct FruitBasket *next;
} FruitBasket;

FruitBasket *head = NULL;
FruitBasket *tail = NULL;
int totloaded = 0;
int totunloaded = 0;

char fruits[15][14] = {"Apple", "Orange", "Pear", "Grapefruit", "Mango", "Grapes", "Strawberry", "Apricot", "Lime", "Sultana", "Bananna", "Avacado", "Blueberries", "Raspberries", "Plums"};

FruitBasket *makebasket()
{
    int randomElement = (rand() % 15) + 1; //1-15 instead of 0-14
    int randomQty = (rand() % 20) + 1;

    FruitBasket *newBasket = malloc(sizeof(FruitBasket));
    strcpy(newBasket->fruittype, fruits[randomElement]);
    newBasket->qty = randomQty;
    newBasket->next = NULL;
    return newBasket;
    //creates a linkless link list element
}

void loadBasket()
{
    //needs to add the makeBasket basket to the linked list (because apparently it already exists prior to the first run)
    FruitBasket *tmp = makebasket(); //stores the address of makebaskets basket

    if (tail != NULL)
    {
        //while it is not at the end of the linked list, iterate
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = tmp; //traverse the linked list until *next == NULL then set as the new end
    }
    //once the end is reached, the basket from makeBasket needs to be added as the pointer *next and the newBasket basket pointer needs to be NULL which it should already be
    if (head == NULL)
    { //un initialised head (1st element)
        head = tmp;
        tail = tmp;
    }
    totloaded += tmp->qty;
}

void unloadBasket()
{
    /*
        Write a function unladbasket which will remove the basket at the front of the of the conveyor
        belt (the head of the linked list), or else write to the console that there is nothing to 
        unload if the conveyor is empty. 
    */
    if (head == NULL)
    {

        printf("No Baskets Present!\n");
    }
    else
    {
        totunloaded += head->qty;
        FruitBasket *tmp = head;
        head = head->next;
        free(tmp);
    }
}

void checkQueue()
{
    /*
    Now write a function checkqueue which will write to console the current 
    number of baskets on the conveyor, and the current total weight of fruit 
    on the conveyor.
    */
    if (head == NULL)
    {
        printf("Conveyor is empty!\n");
    }
    else
    {
        int counter = 0;
        int weight = 0;
        FruitBasket *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            counter++;
            weight += tmp->qty;
        }
        printf("Total Baskets: %d \nTotal Weight: %d\n", counter, weight);
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    checkQueue();
    loadBasket();
    loadBasket();
    loadBasket();
    loadBasket();
    checkQueue();
    unloadBasket();
    checkQueue();
    unloadBasket();
    unloadBasket();
    unloadBasket();
    checkQueue();
    unloadBasket();
}