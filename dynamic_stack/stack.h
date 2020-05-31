#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define nil   NULL
#define true  1
#define false 0
#define and   &&
#define or    ||

typedef struct {
    int number;
} StackItem;

typedef struct node {
    StackItem item;
    struct node* previous;
} _node;

typedef struct stack {
    _node* top;
    int len;
} _stack;

typedef _node* Node;
typedef _stack* Stack;

void init(Stack stack);
void destroy(Stack stack);
void print(Stack stack);

int is_empty(Stack stack);
int size(Stack stack);

int push(Stack stack, StackItem* item);
int pop(Stack stack, StackItem* removed_item);

#endif