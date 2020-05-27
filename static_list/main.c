#include <stdio.h>
#include <stdlib.h>
#include "static_list.h"

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

    init(&list);
    print_if(is_empty(&list), "Empty", nil, nil);
    print_if(is_full(&list), "Full", nil, nil);
    printf("Length: %d\n", length(&list));

    item.number = 12;

    print_if(insert_at_start(&list, &item), "List[1]", get_at_pos(&list, 1), "[]");
    print_if(is_empty(&list), "Empty", nil, nil);
    print_if(is_full(&list), "Full", nil, nil);
    printf("Length: %d\n", length(&list));

    item.number = 33;
    insert_at_start(&list, &item);

    item.number = 45;
    insert_at_end(&list, &item);

    item.number = 56;
    insert_at_start(&list, &item);

    print(&list);
    print_if(is_empty(&list), "Empty", nil, nil);
    print_if(is_full(&list), "Full", nil, nil);
    printf("Length: %d\n", length(&list));

    item.number = 111;
    insert_at_pos(&list, &item, 2);

    item.number = 666;
    insert_at_pos(&list, &item, 3);

    item.number = 77;
    insert_at_end(&list, &item);

    print(&list);
    print_if(is_empty(&list), "Empty", nil, nil);
    print_if(is_full(&list), "Full", nil, nil);
    printf("Length: %d\n", length(&list));

    print_at_pos(&list, length(&list));
    remove_at_end(&list);

    print_at_pos(&list, 1);
    remove_at_start(&list);
    
    print_at_pos(&list, 2);
    remove_at_pos(&list, 2);
    
    print_at_pos(&list, 3);
    remove_at_pos(&list, 3);

    print(&list);
    print_if(is_empty(&list), "Empty", nil, nil);
    print_if(is_full(&list), "Full", nil, nil);
    printf("Length: %d\n", length(&list));

    return 0;
}