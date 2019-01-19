#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void removeNewLine(char name[])
{
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
    {
        name[len - 1] = '\0';
    }
}

void sumRun(int sum)
{
    char x[32];
    int loopInt = 1;
    int intVar;
    fgets(x, 32, stdin);
    intVar = atoi(x);
    sum = sum + intVar;
    if (intVar == 0)
    {
        printf("sum of numbers: %d\n", sum);
    }
    else
    {
        sumRun(sum);
    }
}

typedef struct node
{
    struct intNode *next;

    int intValue;
    double doubleValue;
    float floatValue;
    char charValue[1024];
} node;

node *makeNode(char type, char input)
{
    node *newNode = malloc(sizeof(node));
    if (type == "int")
    {
        newNode->intValue = atoi(input);
    }
    else if (type == "double")
    {
        newNode->doubleValue = atof(input);
    }
    else if ("float")
    {
        newNode->floatValue = atof(input);
    }
    else if ("char")
    {
        strcpy(newNode->charValue, input);
    }

    return newNode;
}

void loadNode(node *head, node *tail, char type, char input)
{
    node *tmp = makeNode(type, input);
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