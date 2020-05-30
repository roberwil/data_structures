#include "stack.h"

void init(Stack* stack) {
    // The stack has no items
    stack->len = 0;
}

void print(Stack* stack) {
    int i, len = size(stack);
    
    printf("top [");
    
    for (i = len; i > 0; i--) {
        if (i != 1) 
            printf("%d -> ", stack->items[i - 1].number);
        else
            printf("%d", stack->items[i - 1].number);
    }

    printf("] bottom\n");
}

int is_empty(Stack* stack) {
    // If the size of the is 0, the it is empty
    return size(stack) == 0;
}

int is_full(Stack* stack) {
    // When the stack has reached its limit
    return size(stack) == MAX_LEN;
}

int size(Stack* stack) {
    // Return the size
    return stack->len;
}

/**
 * Inserts an item at the top of the stack */
int push(Stack* stack, StackItem* item) {
    // Cannot insert if the stack is full :p
    if (is_full(stack)) return false;
    // Insert at the top of the stack
    stack->items[size(stack)] = *item;
    // The stack increases
    stack->len++;
    return true;
}

/**
 * Remove an item from the top of the stack*/
int pop(Stack* stack, StackItem* removed_item) {
    // Cannot remove if the stack is empty :p
    if (is_empty(stack)) return false;
    // Retrieve the item to be removed
    *removed_item = stack->items[size(stack) - 1];
    // the stack decreases, meaning the last top of it will be overwritten
    stack->len--;
    return true;
}