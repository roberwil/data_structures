#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true  1
#define nil   NULL
#define and   &&
#define or    ||
#define is    ==  

typedef enum {
    PRE_ORDER = 1,
    IN_ORDER,
    POST_ORDER  
} TraverseType;

typedef struct {
    char c;
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
int is_empty(BTree tree);
int is_root(BTree tree, Node node);
int is_leaf(Node node);

int node_depth(BTree tree, Node node);
int node_height(Node node);
int node_degree(Node node);

void traverse(BTree tree, TraverseType type);

Node create_root(BTree tree, BTreeItem* item);
Node insert_right(Node parent, BTreeItem* item);
Node insert_left(Node parent, BTreeItem* item);

#endif 