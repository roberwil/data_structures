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

int node_depth(Node node) { 
    return true;
}

int node_height(Node node)  {return true; }
int node_degree(Node node) {return true;}

Node create_node(BTreeItem* item) {
    // create the node
    Node node = (Node)malloc(sizeof(_node));
    // if, somehow, memory is not available
    if (node is nil) return nil;
    // set the content
    node->item = *item;
    // the node does not have any children, yet
    node->left = node->right = nil;
    // return the node, if created
    return node; 
}

Node create_root(BTree tree, BTreeItem* item) {
    // Set the root of the tree
    tree->root = create_node(item);
    // return the root
    return tree->root;
}

Node insert_right(Node parent, BTreeItem* item) {
    // set the right child of the parent node
    parent->right = create_node(item);
    // return the child
    return parent->right;
}

Node insert_left(Node parent, BTreeItem* item) {
    // set the left child of the parent node
    parent->left = create_node(item);
    // return the child
    return parent->left;
}