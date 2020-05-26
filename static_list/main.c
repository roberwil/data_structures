#include <stdio.h>
#include <stdlib.h>
#include "static_list.h"

void print_if(int condition, char* title) {
    if (condition) 
        printf("%s Yes!\n", title);
    else
        printf("%s No!\n", title);
}

int main() {
    List list;
    ListItem item;

    init(&list);
    print_if(is_empty(&list), "Empty?");
    print_if(is_full(&list), "Full?");
    printf("Length: %d\n", length(&list));

    item.number = 12;
    insert_at_start(&list, &item);

    print(&list);
    print_if(is_empty(&list), "Empty?");
    print_if(is_full(&list), "Full?");
    printf("Length: %d\n", length(&list));

    item.number = 33;
    insert_at_start(&list, &item);

    item.number = 45;
    insert_at_end(&list, &item);

    item.number = 56;
    insert_at_start(&list, &item);

    print(&list);
    print_if(is_empty(&list), "Empty?");
    print_if(is_full(&list), "Full?");
    printf("Length: %d\n", length(&list));

    item.number = 111;
    insert_at_pos(&list, &item, 2);

    item.number = 666;
    insert_at_pos(&list, &item, 3);

    item.number = 77;
    insert_at_end(&list, &item);

    print(&list);
    print_if(is_empty(&list), "Empty?");
    print_if(is_full(&list), "Full?");
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
    print_if(is_empty(&list), "Empty?");
    print_if(is_full(&list), "Full?");
    printf("Length: %d\n", length(&list));

    return 0;
}