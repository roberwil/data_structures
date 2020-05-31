#include "queue.h"

void init(Queue q) {
    // the start and the end of the queue are the same
    q->start = q->end = nil;
    // Length is set to 0
    q->len = 0;
}

void destroy(Queue q) {
    // Get the first node
    Node node = q->start, temp;
    // Get the length of the queue
    int i, len = size(q);

    // Free every node
    for (i = 0; i < len; i++) {
        // Store the next node to be freed
        temp = node->next;
        // Free the current node
        free(node);
        // Retrieve the node to be freed;
        node = temp;
    }

    // Initialize the queue
    init(q);
}

void print(Queue q) {
    int i, len = size(q);
    Node node = q->start;

    printf("start [");

    for (i = 0; i < len; i++) {
        if (i != len - 1) 
            printf("%d -> ", node->item.number);
        else
            printf("%d", node->item.number);
        node = node->next;
    }

    printf("] end\n");
}

int size(Queue q) {
    // Return the length of the queue
    return q->len;
}

int is_empty(Queue q) {
    // if the start and end are the same and the length is zero
    return size(q) == 0 and q->start == nil and q->end == nil;
}

/**
 * Insert at the end of the queue*/
int enqueue(Queue q, QueueItem* item) {
    // Create the new node
    Node node = (Node)malloc(sizeof(_node));
    // if, somehow, there is no memory available
    if (node == nil) return false;

    // Set the item
    node->item = *item;
    // The new node always has no next node (it's always the last :p)
    node->next = nil;
    
    // if the list is empty
    if (is_empty(q)) {
        // start and end of the queue are the same
        q->start = q->end = node;
    } else {
        // The old last element now has as the new node as the next node 
        q->end->next = node;
        // the new node becomes the last element of the queue
        q->end = node;
    }
    // the queue increases
    q->len++;
    return true;
}

/**
 * Remove at the start of the queue*/
int dequeue(Queue q, QueueItem* removed_item) {
    // cannot remove from an empty list
    if (is_empty(q)) return false;
    // Get the last node
    Node first_node = q->start;
    // Retrieve the item to be removed
    *removed_item = first_node->item;
    // The second node is now the first element of the queue
    q->start = first_node->next;
    // Free the old first element of the queue
    free(first_node);
    // the queue deecreases
    q->len--;
    return true;
}