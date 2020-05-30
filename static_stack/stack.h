#ifndef STACK_H 
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define nil   NULL
#define true  1
#define false 0
#define and   &&
#define or    ||

#define MAX_LEN 5

typedef struct {
    int number;
} StackItem;

typedef struct {
    StackItem items[MAX_LEN];
    int len;
} Stack;

void init(Stack* stack);
void print(Stack* stack);

int is_empty(Stack* stack);
int is_full(Stack* stack);
int size(Stack* stack);

int push(Stack* stack, StackItem* item);
int pop(Stack* stack);

#endif