#include "queue.h"

void init(Queue* q) {
    // Initialize the queue is the same as setting its length to 0
    q->len = 0;
}

void print(Queue* q) {
    int i, len = size(q);
    
    printf("start [");
    
    for (i = 0; i < len; i++)
        if (i != len - 1)
            printf("%d -> ", q->items[i].number);
        else
            printf("%d", q->items[i].number);

    printf("] end\n");
}

int size(Queue* q) {
    // Returns the length of the queue
    return q->len;
}

int is_empty(Queue* q) {
    // if the length is 0, the there are no items
    return size(q) == 0;
}

int is_full(Queue* q) {
    // if the MAX_LEN of the queue is reached, the it's full
    return size(q) == MAX_LEN;
}

/**
 * Inserts an item at the end of the queue*/
int enqueue(Queue* q, QueueItem* item) {
    // if the queue is full, item cannot be inserted
    if (is_full(q)) return false;
    // Insert at the end
    q->items[size(q)] = *item;
    // The queue increases
    q->len++;
    return true;
}

/**
 * Removes from the start of the queue*/
int dequeue(Queue* q, QueueItem* removed_item) {
    // cannot remove 'cause the queue is empty
    if (is_empty(q)) return false;
    int i, len = size(q);
    // retrieve the item to be removed
    *removed_item = q->items[0];
    // Every item moves a position backwards
    for (i = 0; i < len; i++)
        q->items[i] = q->items[i+1];
    // the queue decreases
    q->len--;
    return true;
}