#ifndef STACK_H 
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define nil   NULL
#define true  1
#define false 0
#define and   &&
#define or    ||

#define MAX_LEN 10

typedef struct {
    int number;
} StackItem;

typedef struct stack {
    StackItem items[MAX_LEN];
    int len;
} stack;

typedef stack* Stack;

#endif