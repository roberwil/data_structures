#ifndef QUEUE_H 
#define QUEUE_H

/**
 * A Queue complies with FIFO, which means that the first inserted item
 * is always the first to be removed, hence FIFO - First in, first out
 */

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

typedef struct _node {
    QueueItem items[MAX_LEN];
    int len;
} _node;

typedef struct {
    _node* start;
    _node* end;
    int len; 
} queue;

typedef _node* Node;
typedef queue* Queue;

void init(Queue q);
void print(Queue q);
void destroy(Queue q);

int size(Queue q);
int is_empty(Queue q);

int enqueue(Queue q, QueueItem* item);
int dequeue(Queue q, QueueItem* removed_item);

#endif