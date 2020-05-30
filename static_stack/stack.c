#include "stack.h"

void init(Stack* stack) {
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
    return size(stack) == 0;
}

int is_full(Stack* stack) {
    return size(stack) == MAX_LEN;
}

int size(Stack* stack) {
    return stack->len;
}

int push(Stack* stack, StackItem* item) {
    if (is_full(stack)) return false;

    stack->items[size(stack)] = *item;
    stack->len++;
    return true;
}

int pop(Stack* stack) {
    if (is_empty(stack)) return false;

    stack->len--;
    return true;
}