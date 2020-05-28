#include "linked_list.h"

void init(List list) {
    list->start = list->end = nil;
    list->len = 0;
}

void destroy(List list) {
    
}

int is_empty(List list) {
    return list->len == 0 && list->start == nil && list->end == nil;
}

int insert_start(List list, ListItem* item) {
    
    Node nd = (Node)malloc(sizeof(node));

    if (nd == nil) return FALSE;

    nd->item = *item;

    if (is_empty(list)) {
        list->end = nd;
        nd->next = nil;
    } else 
        nd->next = list->start;

    list->start = nd;
    list->len++;
    return TRUE;

}


int insert_end(List list, ListItem* item) {

    Node nd = (Node)malloc(sizeof(node));

    if (nd == nil) return FALSE;

    nd->item = *item;
    nd->next = nil;

    if (is_empty(list))
        list->start = nd; 
    else
        list->end->next = nd;

    list->end = nd;
    list->len++;

    return TRUE;

}

