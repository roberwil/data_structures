#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

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
    List list;
    ListItem item;

    init(list);
    print_if(is_empty(list), "Empty", nil, nil);

    item.number = 12;
    insert_start(list, &item);

    item.number = 0;
    insert_start(list, &item);

    item.number = 1;
    insert_start(list, &item);

    item.number = 2;
    insert_end(list, &item);

    item.number = 5;
    insert_end(list, &item);

    item.number = 13;
    insert_end(list, &item);

    print_if(is_empty(list), "Empty", nil, nil);
    print(list);
    printf("Length: %d\n", len(list));

    remove_start(list);
    remove_end(list);

    print(list);
    printf("Length: %d\n", len(list));
    
    destroy(list);
    return 0;
}