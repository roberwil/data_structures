#include "stack.h"

void init(Stack stack) {
    stack->top = nil;
    stack->len = 0;
}

void destroy(Stack stack) {
    Node node = stack->top, temp;
    int len = size(stack);

    for (int i = len; i > 0; i--) {
        temp = node->previous;
        free(node);
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
    return size(stack) == 0 and stack->top == nil;
}

int size(Stack stack) {
    return stack->len;
}

int push(Stack stack, StackItem* item) {
    Node node = (Node)malloc(sizeof(_node));

    if (node == nil) return false;

    if (is_empty(stack))
        node->previous = nil;
    else
        node->previous = stack->top;

    node->item = *item;
    stack->top = node;    
    stack->len++;
    return true;
}

int pop(Stack stack) {
    if (is_empty(stack)) return false;

    Node node = stack->top;
    
    stack->top = node->previous;
    free(node);
    stack->len--;

    return true;
}