#ifndef STACK_H
#define STACK_H

typedef struct {
    int number;
} ListItem;

typedef struct node {
    ListItem item;
    struct node* next;
} node;

typedef struct stack {
    node* top;
} stack;

void init


#endif