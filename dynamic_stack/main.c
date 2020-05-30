#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void print_if(int condition, char* title, char* yes, char* no) {

    #ifndef nil
    #define nil NULL
    #endif

    if (title != nil) 
        printf("%s = ", title);

    if (condition) {
        if (yes == nil)
            printf("Yes!\n");
        else
            printf("%s", yes);
    } else {
        if (no == nil)
            printf("No!\n");
        else 
            printf("%s", no);
    }

}

int main() {
    Stack stack;
    StackItem item;

    init(stack);
    print_if(is_empty(stack), "Empty", nil, nil);
    print(stack);
    printf("Length: %d\n", size(stack));

    item.number = 12;
    push(stack, &item);

    item.number = 22;
    push(stack, &item);

    item.number = 33;
    push(stack, &item);

    item.number = 44;
    push(stack, &item);

    item.number = 55;
    push(stack, &item);

    print_if(is_empty(stack), "Empty", nil, nil);
    print(stack);
    printf("Length: %d\n", size(stack));

    pop(stack);
    pop(stack);
    pop(stack);

    print_if(is_empty(stack), "Empty", nil, nil);
    print(stack);
    printf("Length: %d\n", size(stack));

    destroy(stack);
    return 0;
}