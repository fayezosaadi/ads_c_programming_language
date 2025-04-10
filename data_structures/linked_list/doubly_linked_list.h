//
// Created by tech4life on 05/04/25.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct DList DList;

DList *list_create(void (*print_func)(const void *value));

void list_destroy(DList *list);

void list_prepend(DList *list, void *value);

void list_append(DList *list, void *value);

void list_insert(DList *list, size_t index, void *value);

void list_remove(DList *list, size_t index);

void list_reverse(DList *list);

bool is_list_empty(const DList *list);

void print_list(const DList *list);

#endif //DOUBLY_LINKED_LIST_H
