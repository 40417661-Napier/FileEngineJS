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

typedef struct node
{
    struct node *next;

    int intValue;
    double doubleValue;
    float floatValue;
    char charValue[1024];

} node;

node *head = NULL;
node *tail = NULL;

node *makeNode(char type[], char input[])
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
    else if (type == "float")
    {
        newNode->floatValue = atof(input);
    }
    else if (type == "char")
    {
        strcpy(newNode->charValue, input);
    }

    return newNode;
}

void loadNode(char type[], char input[])
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

void unloadHeadNode()
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

void traverseNode()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        node *passThrough = head;
        while (passThrough->next != NULL)
        {
            printf("%s\n", passThrough->charValue);
            printf("%d\n", passThrough->intValue);
            printf("%f\n", passThrough->doubleValue);
            printf("%f\n\n", passThrough->floatValue);
            passThrough = passThrough->next;
        }
        printf("%s\n",passThrough->charValue);
        printf("%d\n", passThrough->intValue);
        printf("%f\n", passThrough->doubleValue);
        printf("%f\n\n", passThrough->floatValue);
    }
}