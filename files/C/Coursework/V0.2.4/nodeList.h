#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node
{
    struct intNode *next;

    int intValue;

}node;

node *head = NULL;
node *tail = NULL;

node *makeNode(int input)
{
    node *newNode = malloc(sizeof(node));

    newNode->intValue = input;

    return newNode;
}

void loadNode(char input)
{
    node *tmp = makeNode(input);
    if (tail != NULL)
    {
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = tmp;
    }
    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
}

void unloadHeadNode(node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
    }
}