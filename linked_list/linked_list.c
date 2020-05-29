#include "linked_list.h"

void init(List list) {
    list->start = list->end = nil;
    list->len = 0;
}

void destroy(List list) {
    Node nd = list->start, temp;

    for (int i = 0; i < len(list); i++) {
        temp = nd->next;
        free(nd);
        nd = temp;
    }
}

void print(List list) {

    if(is_empty(list)) {
        printf("[]\n");
        return;
    }

    Node nd = list->start; 
    int _len = len(list);

    for (int i = 0; i < _len; i++) {
        if (i == 0)
            printf("[%d, ", nd->item.number);
        else if (i == _len - 1)
            printf("%d]", nd->item.number);
        else
            printf("%d, ", nd->item.number);

        nd = nd->next;
    }

    printf("\n");
}

int is_empty(List list) {
    return list->len == 0 && list->start == nil && list->end == nil;
}

int len(List list) {
    return list->len;
}

int insert_start(List list, ListItem *item) {

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

int insert_end(List list, ListItem *item) {

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

int remove_start(List list) {
    if (is_empty(list)) return FALSE;

    Node first_node = list->start;

    list->start = first_node->next;
    free(first_node);
    list->len--;

    return TRUE;
}

int remove_end(List list) {
    if (is_empty(list)) return FALSE;
    
    int i, _len = len(list);
    Node last_node = list->end, nd = list->start;

    for (int i = 0; i < _len - 2; i++)
        nd = nd->next;

    list->end = nd;
    free(last_node);
    list->len--;

    return TRUE;
}
