#include "static_list.h"

void init(List* list) {
    list->size = 0;
}

void print(List* list) {

    int i, len = length(list);

    if (is_empty(list))
        printf("[]\n");
    else {
        printf("[");
        for (i = 0; i < len; i++)
            if (i == len - 1)
                printf("%d]\n", list->items[i].number);
            else
                printf("%d, ", list->items[i].number);
    }

}

void print_at_pos(List* list, int pos) {

    if (is_empty(list) || pos < 1 || pos > length(list))
        printf("[]\n");
    else
        printf("[%d]\n", list->items[pos - 1].number);

}   

char* get_at_pos(List* list, int pos) {

    if (is_empty(list) || pos < 1 || pos > length(list))
        return "[]\n"
    else
        return printf("[%d]\n", list->items[pos - 1].number);

}

int is_empty(List* list) {
    return length(list) == 0;
}

int is_full(List* list) {
    return length(list) == MAX_SIZE;
}
 
int length(List* list) {
    return list->size;
} 

int insert_at_end(List* list, ListItem* item) {
    
    //return insert_at_pos(list, item, length(list) + 1);

    if (is_full(list)) 
        return FALSE;

    list->items[length(list)] = *item;
    list->size++;

    return TRUE;

}

int insert_at_start(List* list, ListItem* item) {

    //return insert_at_pos(list, item, 1);

    if (is_full(list))
        return FALSE;
    
    for (int i = length(list); i > 0; i--) {
        list->items[i] = list->items[i - 1];
    }

    list->items[0] = *item;
    list->size++;
    
    return TRUE;

}

int insert_at_pos(List* list, ListItem* item, int pos) {
    
    if (is_full(list) || pos < 1 || pos > MAX_SIZE)
        return FALSE;

    int i, len = length(list);
    pos = (pos > len)? len : pos - 1; 

    for (i = len; i > pos; i--)
        list->items[i] = list->items[i - 1];
    
    list->items[pos] = *item;
    list->size++;

    return TRUE;

}

int remove_at_start(List* list) {

    //return remove_at_pos(list, 1);

    if (is_empty(list))
        return FALSE;

    int i, len = length(list);

    for (i = 0; i < len - 1; i++)
        list->items[i] = list->items[i + 1];

    list->size--;

    return TRUE;

}

int remove_at_end(List* list) {

    //return remove_at_pos(list, length(list));

    if (is_empty(list))
        return FALSE;

    list->size--;
    
    return TRUE;

}

int remove_at_pos(List* list, int pos) {

    if (is_empty(list) || pos < 1 || pos > MAX_SIZE)
        return FALSE;

    int i, len = length(list);
    pos = (pos > len)? len : pos - 1; 

    for (i = pos; i < len - 1; i++)
        list->items[i] = list->items[i + 1];

    list->size--;

    return TRUE;

}

