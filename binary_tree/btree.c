#include "btree.h"

void init(BTree tree) {
    tree->root = nil;
}

Node create_root(BTree tree, BTreeItem* item) {
    Node root = (Node)malloc(sizeof(_node));

    if (root == nil) return false;

    root->item = *item;
    root->left = root->right = nil;

    return root;
}

Node insert_right(Node node, BTreeItem* item) {

}

Node insert_left(Node node, BTreeItem* item) {
    
}