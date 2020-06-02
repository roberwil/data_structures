#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true  1
#define nil   NULL
#define and   &&
#define or    ||

typedef struct {
    int number;
} BTreeItem;

typedef struct _node {
    BTreeItem item;
    struct _node* right;
    struct _node* left;
} _node;

typedef struct  {
    _node* root;
} _btree;

typedef _node* Node;
typedef _btree* BTree;

void init(BTree tree);
Node create_root(BTree tree, BTreeItem* item);

Node insert_right(Node node, BTreeItem* item);
Node insert_left(Node node, BTreeItem* item);

#endif 