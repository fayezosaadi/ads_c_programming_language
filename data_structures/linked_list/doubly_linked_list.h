//
// Created by tech4life on 05/04/25.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct List List;

List *list_create(void (*print_func)(const void *value));

void list_destroy(List *list);

void list_prepend(List *list, void *value);

void list_append(List *list, void *value);

void list_insert(List *list, size_t index, void *value);

void list_remove(List *list, size_t index);

void list_reverse(List *list);

bool is_list_empty(const List *list);

void print_list(const List *list);

#endif //DOUBLY_LINKED_LIST_H
