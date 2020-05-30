#include "stack.h"

void init(Stack stack) {
    // There is not top of the stack
    stack->top = nil;
    // the stack is empty
    stack->len = 0;
}

void destroy(Stack stack) {
    // Get the top of the stack
    Node node = stack->top, temp;
    // Get the size of the stack
    int len = size(stack);

    // Free every node 
    for (int i = len; i > 0; i--) {
        // Get the penultimate node of the stak
        temp = node->previous;
        // Fee the top of the stack
        free(node);
        // The penultimate node is now the top of the stack
        node = temp;
    }
}

void print(Stack stack) {
    Node node = stack->top;
    int len = size(stack);

    printf("top [");

    for (int i = 0; i < len; i++) {
        if (i != len - 1)
            printf("%d -> ", node->item.number);
        else
            printf("%d", node->item.number);
        
        node = node->previous;
    }

    printf("] bottom\n");
}

int is_empty(Stack stack) {
    // If there no items in the stack
    return size(stack) == 0 and stack->top == nil;
}

int size(Stack stack) {
    // Return the size of the stack
    return stack->len;
}

/**
 * Inserts an item at the top of the stack */
int push(Stack stack, StackItem* item) {
    // Create the new node
    Node node = (Node)malloc(sizeof(_node));
    // if, somehow, there is no memory available
    if (node == nil) return false;
    
    if (is_empty(stack))
        // the stack is empty, so the new node is the top, thus it has no previous node
        node->previous = nil;
    else
        // The new node has as previous node the old top of the stack
        node->previous = stack->top;

    // Set the item  
    node->item = *item;
    // The new node becomes the top of the stack
    stack->top = node;    
    // The stack increases
    stack->len++;
    return true;
}

/**
 * Remove an item from the top of the stack*/
int pop(Stack stack) {
    // Cannot remove if the stack is empty :p
    if (is_empty(stack)) return false;
    // Get the top of the stack
    Node node = stack->top;
    // The penultimate node becomes the top of the stack
    stack->top = node->previous;
    // Free the old top
    free(node);
    // The stack decreases
    stack->len--;
    return true;
}