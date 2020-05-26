#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7
#define FALSE    0
#define TRUE     1

typedef struct {
    int number;
} ListItem;

typedef struct {
    ListItem items[MAX_SIZE];
    int size;
} List;

void init(List* list);
void print(List* list);
void print_at_pos(List* list, int pos);

int is_empty(List* list);
int is_full(List* list);
int length(List* list);

int insert_at_end(List* list, ListItem* item);
int insert_at_start(List* list, ListItem* item);
int insert_at_pos(List* list, ListItem* item, int pos);

int remove_at_start(List* list);
int remove_at_end(List* list);
int remove_at_pos(List* list, int pos);

#endif