#ifndef QUEUE_H 
#define QUEUE_H

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
} QueueItem;

typedef struct {
    QueueItem items[MAX_LEN];
    int len;
} Queue;

void init(Queue* q);
void print(Queue* q);

int size(Queue* q);
int is_empty(Queue* q);
int is_full(Queue* q);

int enqueue(Queue* q, QueueItem* item);
QueueItem dequeue(Queue* q);

#endif