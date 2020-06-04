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

    init(tree);
    item.number = 0;
    create_root(tree, &item);

    return 0;
}