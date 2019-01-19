#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define R 6371
#define TO_RAD (3.1415926536 / 180)

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

double dist(double th1, double ph1, double th2, double ph2)
{
    double dx, dy, dz;
    ph1 -= ph2;
    ph1 *= TO_RAD, th1 *= TO_RAD, th2 *= TO_RAD;
    dz = sin(th1) - sin(th2);
    dx = cos(ph1) * cos(th1) - cos(th2);
    dy = sin(ph1) * cos(th1);
    return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
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
    if(type == "int"){
        newNode -> intValue = atoi(input);
    }
    else if (type == "double")
    {
        newNode -> doubleValue = atof(input);
    }
    else if ("float")
    {
        newNode -> floatValue = atof(input);    
    }
    else if ("char")
    {
        strcpy(newNode -> charValue, input);
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