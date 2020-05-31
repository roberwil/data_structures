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
    StackItem item, removed_item;

    init(stack);
    print_if(is_empty(stack), "Empty", nil, nil);
    printf("Length: %d\n", size(stack));
    print(stack);

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
    printf("Length: %d\n", size(stack));
    print(stack);

    pop(stack, &removed_item);
    printf("Removed %d\n", removed_item.number);

    pop(stack, &removed_item);
    printf("Removed %d\n", removed_item.number);

    pop(stack, &removed_item);
    printf("Removed %d\n", removed_item.number);

    print_if(is_empty(stack), "Empty", nil, nil);
    printf("Length: %d\n", size(stack));
    print(stack);

    destroy(stack);
    return 0;
}