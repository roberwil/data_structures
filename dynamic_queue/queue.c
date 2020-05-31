#include "queue.h"

void init(Queue q);
void print(Queue q);
void destroy(Queue q);

int size(Queue q);
int is_empty(Queue q);

int enqueue(Queue q, QueueItem* item);
int dequeue(Queue q, QueueItem* removed_item);