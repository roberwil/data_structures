#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define FALSE    0
#define TRUE     1
#define nil      NULL

typedef struct {
    int number;
} ListItem;

typedef struct node {
    ListItem item;
    struct node* next;
} node;

typedef struct {
    node* start;
    node* end;
    int len;
} list;

typedef node* Node;
typedef list* List;

void init(List list);
void destroy(List list);
void print(List list);

int is_empty(List list);
int len(List list);

int insert_start(List list, ListItem* item);
int insert_end(List list, ListItem* item);

int remove_start(List list);
int remove_end(List list);

#endif