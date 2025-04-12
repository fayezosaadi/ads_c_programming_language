//
// Created by tech4life on 29/03/25.
//

#ifndef BST_H
#define BST_H
#include <stdbool.h>

typedef struct BST BST;

BST *bst_create(int (*compare_func)(const void *, const void *), void (*print_func)(const void *value));

void bst_destroy(BST *tree);

bool bst_insert(BST *tree, void *value);

bool bst_lookup(const BST *tree, const void *value);

bool bst_remove(BST *tree, const void *value);

void bst_traverse(const BST *tree);

#endif //BST_H
