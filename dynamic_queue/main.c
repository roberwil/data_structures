#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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
    Queue q;
    QueueItem item, removed_item;

    init(q);
    print_if(is_empty(q), "Empty", nil, nil);
    printf("Length: %d\n", size(q));
    print(q);

    item.number = 12;
    print_if(enqueue(q, &item), "Inserted", nil, nil);

    item.number = 22;
    enqueue(q, &item);

    item.number = 33;
    enqueue(q, &item);

    item.number = 44;
    enqueue(q, &item);

    item.number = 55;
    enqueue(q, &item);

    print_if(is_empty(q), "Empty", nil, nil);
    printf("Length: %d\n", size(q));
    print(q);

    dequeue(q, &removed_item);
    printf("Removed %d\n", removed_item.number);

    dequeue(q, &removed_item);
    printf("Removed %d\n", removed_item.number);

    dequeue(q, &removed_item);
    printf("Removed %d\n", removed_item.number);

    print_if(is_empty(q), "Empty", nil, nil);
    printf("Length: %d\n", size(q));
    print(q);

    destroy(q);
    return 0;
}