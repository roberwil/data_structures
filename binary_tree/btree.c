#include "btree.h"

void init(BTree tree) {
    tree->root = nil;
}

int is_empty(BTree tree) {
    return tree->root == nil;
}

int is_root(BTree tree, Node node) {
    return node == tree->root;
}

Node create_root(BTree tree, BTreeItem* item) {
    Node root = (Node)malloc(sizeof(_node));

    if (root == nil) return false;

    root->item = *item;
    root->left = root->right = nil;

    return root;
}

Node insert_right(Node parent, BTreeItem* item) {
    Node son = (Node)malloc(sizeof(_node));

    if (son == nil) return false;

    son->item = *item;
    son->left = son->right = nil;
    parent->right = son;

    return son;
}

Node insert_left(Node parent, BTreeItem* item) {
    Node son = (Node)malloc(sizeof(_node));

    if (son == nil) return false;

    son->item = *item;
    son->left = son->right = nil;
    parent->left = son;

    return son;
}