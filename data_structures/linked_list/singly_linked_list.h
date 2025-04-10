//
// Created by tech4life on 05/04/25.
//

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct SList SList;

SList *list_create(void (*print_func)(const void *value));

void list_destroy(SList *list);

void list_prepend(SList *list, void *value);

void list_append(SList *list, void *value);

void list_insert(SList *list, size_t index, void *value);

void list_remove(SList *list, size_t index);

void list_reverse(SList *list);

bool is_list_empty(const SList *list);

void print_list(const SList *list);

#endif //SINGLY_LINKED_LIST_H
