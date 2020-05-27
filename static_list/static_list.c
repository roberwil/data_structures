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
        return "[]\n";
    else { 
        static char result[10];
        sprintf(result, "[%d]\n", list->items[pos - 1].number);
        return result;
    }
    
}

int is_empty(List* list) {
    // If the length of the list is 0, then it is empty
    return length(list) == 0;
}

int is_full(List* list) {
    // If the length of the list is at its maximum value, then it is full
    return length(list) == MAX_SIZE;
}

int length(List* list) {
    // Size tracks the length of the list 
    return list->size;
} 

int insert_at_end(List* list, ListItem* item) {
    
    /**
     * It is an alernative implementation, since
     * insertion at the end of the list is the same 
     * as inserting at the next free position of it 
     * which is the its length + 1
     **/
    //return insert_at_pos(list, item, length(list) + 1);

    // Pre-condition: the list must not be full
    if (is_full(list)) 
        return FALSE;

    // Add the item to the list
    list->items[length(list)] = *item;
    // The length of the list increases
    list->size++;

    return TRUE;

}

int insert_at_start(List* list, ListItem* item) {

    /**
     * It is an alernative implementation, since
     * insertion at the start of the list is the same 
     * as inserting at position 1 
     */
    //return insert_at_pos(list, item, 1); 

    // Pre-condition: the list must not be full
    if (is_full(list))
        return FALSE;
    
    /** 
     * Since it is an insertion at the start, 
     * every item in the list has to move a position foward
     */
    for (int i = length(list); i > 0; i--) {
        list->items[i] = list->items[i - 1];
    }

    // Add the item to the list
    list->items[0] = *item;
    // The length of the list increases
    list->size++;
    
    return TRUE;

}

int insert_at_pos(List* list, ListItem* item, int pos) {

    /**
     * Pre-conditions: the list must not be full, position (pos)
     * has to comply with {1 <= pos <= MAX_SIZE}.
     * Note: pos = 1 refers to the first postion in the lsit,
     * which is indexed as '0', thus "pos-1".
     */
    if (is_full(list) || pos < 1 || pos > MAX_SIZE)
        return FALSE;

    int i, len = length(list);
    // If the given position is greater than the length, the next free position is chosen
    pos = (pos > len)? len : pos - 1; 

    /** 
     * Every item in the list has to move a position foward,
     * if the insertion is at the start or anywhere in the middle of the list 
     */
    for (i = len; i > pos; i--)
        list->items[i] = list->items[i - 1];
    
    // Add the item to the list
    list->items[pos] = *item;
    // The length of the list increases
    list->size++;

    return TRUE;

}

int remove_at_start(List* list) {
    
    /**
     * It is an alernative implementation, since
     * removing at the start of the list is the same 
     * as removing the first item which is in position 1
     */
    //return remove_at_pos(list, 1);

    // Pre-condition: the list must not be empty
    if (is_empty(list))
        return FALSE;

    int i, len = length(list);

    /** 
     * Since it is an removal at the start, 
     * every item in the list has to move a position backwards,
     * so that to overwrite the first item
     */
    for (i = 0; i < len - 1; i++)
        list->items[i] = list->items[i + 1];

    // The length of the list decreases
    list->size--;

    return TRUE;

}

int remove_at_end(List* list) {

    /**
     * It is an alernative implementation, since
     * removing at the end of the list is the same 
     * as removing the last item which is the its length
     **/
    //return remove_at_pos(list, length(list));

    // Pre-condition: the list must not be empty
    if (is_empty(list))
        return FALSE;

    // The length of the list decreases
    list->size--;
    
    return TRUE;

}

int remove_at_pos(List* list, int pos) {

    /**
     * Pre-conditions: the list must not be empty, position (pos)
     * has to comply with {1 <= pos <= MAX_SIZE}.
     * Note: pos = 1 refers to the first postion in the lsit,
     * which is indexed as '0', thus "pos-1".
     */
    if (is_empty(list) || pos < 1 || pos > MAX_SIZE)
        return FALSE;

    int i, len = length(list);
    // If the given position is greater than the length, the next free position is chosen
    pos = (pos > len)? len : pos - 1; 

    /** 
     * Every item in the list has to move a position backwards,
     * if the removal is at the start or anywhere in the middle of the list 
     */
    for (i = pos; i < len - 1; i++)
        list->items[i] = list->items[i + 1];

    // The length of the list decreases
    list->size--;

    return TRUE;

}

