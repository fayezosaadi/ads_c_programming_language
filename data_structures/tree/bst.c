//
// Created by tech4life on 29/03/25.
//

#include "bst.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
    void *value;
    Node *left;
    Node *right;
};

struct BST {
    Node *root;

    int (*compare)(const void *, const void *);

    void (*print)(const void *);
};

static Node *node_create(void *value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static void node_destroy(Node *node) {
    if (!node) return;
    if (node->left) node_destroy(node->left);
    if (node->right) node_destroy(node->right);
    free(node);
}

static void node_traverse(Node *node, void (*print)(const void *)) {
    if (!node) return;
    node_traverse(node->left, print);
    print(node->value);
    node_traverse(node->right, print);
}

BST *bst_create(int (*compare_func)(const void *, const void *), void (*print_func)(const void *value)) {
    BST *tree = malloc(sizeof(BST));
    tree->root = NULL;
    tree->compare = compare_func;
    tree->print = print_func;
    return tree;
}

void bst_destroy(BST *tree) {
    if (!tree) return;
    if (tree->root) node_destroy(tree->root);
    free(tree);
}

bool bst_insert(BST *tree, void *value) {
    Node *node = node_create(value);

    if (!tree->root) {
        tree->root = node;
        return tree;
    }

    Node *current = tree->root;
    while (current) {
        const int cmp = tree->compare(value, current->value);
        if (cmp < 0) {
            if (current->left) current = current->left;
            else {
                current->left = node;
                return true;
            }
        } else {
            if (current->right) current = current->right;
            else {
                current->right = node;
                return true;
            }
        }
    }

    return false;
}

bool bst_lookup(const BST *tree, const void *value) {
    const Node *current = tree->root;
    while (current) {
        const int cmp = tree->compare(value, current->value);
        if (cmp == 0) return true;
        current = cmp < 0 ? current->left : current->right;
    }

    return false;
}

bool bst_remove(BST *tree, const void *value) {
    if (!tree || !tree->root) return false;

    Node *current = tree->root;
    Node *parent = NULL;

    // Find the node to remove
    while (current) {
        const int cmp = tree->compare(value, current->value);
        if (cmp == 0) break;

        parent = current;
        current = cmp < 0 ? current->left : current->right;
    }

    if (!current) return false;

    Node *successor = NULL;

    // Case 1: Node has no right child
    if (!current->right) successor = current->left;

    // Case 2: Node's right child has no left child
    else if (!current->right->left) {
        current->right->left = current->left;
        successor = current->right;
    }

    // Case 3: Node's right child has a left child
    else {
        successor = current->right->left;
        Node *successor_parent = current->right;

        while (successor->left) {
            successor_parent = successor;
            successor = successor->left;
        }

        successor_parent->left = successor->right;
        successor->left = current->left;
        successor->right = current->right;
    }


    if (!parent) tree->root = successor;
    else if (parent->left == current) parent->left = successor;
    else parent->right = successor;

    free(current);
    return true;
}

void bst_traverse(const BST *tree) {
    Node *node = tree->root;
    node_traverse(node, tree->print);
}
