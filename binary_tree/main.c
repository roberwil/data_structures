#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

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
    BTreeItem item;
    BTree tree;
    Node A, B, C, D, E, F, G, H, I;

    init(tree);

    item.c = 'A';
    A = create_root(tree, &item);

    item.c = 'B';
    B = insert_left(A, &item);

    item.c = 'C';
    C = insert_left(A, &item);

    item.c = 'D';
    D = insert_left(B, &item);

    item.c = 'E';
    E = insert_left(C, &item);

    item.c = 'F';
    F = insert_left(C, &item);

    item.c = 'G';
    G = insert_left(D, &item);

    item.c = 'H';
    H = insert_left(E, &item);

    item.c = 'I';
    I = insert_left(E, &item);

    return 0;
}