#include "list.h"

void init(List list) {
    // The head and tail of the list point to nil
    list->start = list->end = nil;
    // The length o f the list is set to 0
    list->len = 0;
}

void destroy(List list) {
    Node nd = list->start, temp;

    //Loop every node of the list and free one at a time starting from the first one
    for (int i = 0; i < len(list); i++) {
        // Get the next node
        temp = nd->next;
        // Free the previous node
        free(nd);
        // Set the next node (used in the next iteration)
        nd = temp;
    }

    // Initialize the list
    init(list);
}

void print(List list) {
    if(is_empty(list)) {
        printf("[]\n");
        return;
    }

    Node nd = list->start; 
    int _len = len(list);


    for (int i = 0; i < _len; i++) {
        if (i == 0)
            printf("[%d, ", nd->item.number);
        else if (i == _len - 1)
            printf("%d]", nd->item.number);
        else
            printf("%d, ", nd->item.number);

        nd = nd->next;
    }

    printf("\n");
}

int is_empty(List list) {
    // Check whether the list is empty or not
    return list->len == 0 && list->start == nil && list->end == nil;
}

int len(List list) {
    // Returns the length of the list
    return list->len;
}

int insert_start(List list, ListItem *item) {
    // Create the node to be inserted
    Node nd = (Node)malloc(sizeof(node));
    // If, somehow, memory is not available
    if (nd == nil) return FALSE;

    // Set the node item
    nd->item = *item;
    // The new head points to no previous node
    nd->previous = nil;

    // if the list is empty
    if (is_empty(list)) {
        // The head is the tail
        list->end = nd;
        // the head and the tail have no next or previous node
        nd->next = nil;
    } else {
        // The new node now points to the old head
        nd->next = list->start;
        // The old head has the new head as the previous node
        list->start->previous = nd;
    }

    // The new node becomes the head
    list->start = nd;
    // The length of the list increases
    list->len++;

    return TRUE;
}

int insert_end(List list, ListItem *item) {
    // Create the node to be inserted
    Node nd = (Node)malloc(sizeof(node));
    // If, somehow, memory is not available
    if (nd == nil) return FALSE;
    // Set the node item
    nd->item = *item;
    // Since it is an insertion at the end, the node has to point to nowhere
    nd->next = nil;

    if (is_empty(list)) {
        // if the list is empty, the head and the tail have to be the same
        list->start = nd;
        // There is no previous node to point to
        nd->previous = nil;
    } else {
        // the old tail has as next node the new tail 
        list->end->next = nd;
        // The new tail has as previous node the old tail
        nd->previous = list->end;
    }

    // The new node becomes the tail
    list->end = nd;
    // The length of the list increases
    list->len++;

    return TRUE;
}

int remove_start(List list) {
    // If the list is empty, there is nothing to remove
    if (is_empty(list)) return FALSE;

    // Get the first node
    Node first_node = list->start;

    if (list->start == list->end)
        // if list is of length 1, then the head and the tail must point to nowhere
        list->start = list->end = nil;
    else {
        // the node pointed by the old head becomes the head
        list->start = list->start->next;
        // the frist node has no previous node
        list->start->previous =  nil;
    }

    // Free the old head
    free(first_node);
    // The length of the list decreases
    list->len--;

    return TRUE;
}

int remove_end(List list) {
    // If the list is empty, there is nothing to remove
    if (is_empty(list)) return FALSE;

    // If the list is of size of 1
    if (list->start == list->end) {
        // Free the single node
        free(list->start);
        // Head an tail point to nowhere
        list->start = list->end = nil;
    } else {
        // Get the last node
        Node last_node = list->end;
        // The penultimate node, which is the previous node of the last node, is now the last node 
        list->end = last_node->previous;
        // The new tail has no next node
        list->end->next = nil;
        // Free the old tail
        free(last_node);
    }

    // The length of the list decreases
    list->len--;

    return TRUE;
}
