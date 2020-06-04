#include "btree.h"

void init(BTree tree) {
    // the root does not exist
    tree->root = nil;
}

int is_empty(BTree tree) {
    // if the root is null, then the tree is empty
    return tree->root is nil;
}

int is_root(BTree tree, Node node) {
    // if the node is the root
    return node is tree->root;
}

int is_leaf(Node node) {
    // if the node does not have any children
    return node->left is nil and node->right is nil;
}

Node create_root(BTree tree, BTreeItem* item) {
    // create the root node
    Node root = (Node)malloc(sizeof(_node));
    // if, somehow, memory is not available
    if (root is nil) return false;
    // set the content
    root->item = *item;
    // the root does not have any children, yet
    root->left = root->right = nil;

    return root;
}

Node insert_right(Node parent, BTreeItem* item) {
    // create the son
    Node son = (Node)malloc(sizeof(_node));
    // if, somehow, memory is unavailable
    if (son == nil) return false;
    // set the content
    son->item = *item;
    // son does not have children yet
    son->left = son->right = nil;
    // parent has now a son on the right
    parent->right = son;

    return son;
}

Node insert_left(Node parent, BTreeItem* item) {
    // create the son
    Node son = (Node)malloc(sizeof(_node));
    // if, somehow, memory is unavailable
    if (son == nil) return false;
    // set the content
    son->item = *item;
    // son does not have children yet
    son->left = son->right = nil;
     // parent has now a son on the left   
    parent->left = son;

    return son;
}