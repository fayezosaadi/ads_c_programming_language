//
// Created by tech4life on 05/04/25.
//

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct SinglyList SinglyList;

SinglyList *singly_list_create(void);

void singly_list_destroy(SinglyList *list);

void singly_list_prepend(SinglyList *list, void *value);

void singly_list_append(SinglyList *list, void *value);

void singly_list_insert(SinglyList *list, size_t index, void *value);

void singly_list_remove(SinglyList *list, size_t index);

void singly_list_reverse(SinglyList *list);

bool is_singly_list_empty(const SinglyList *list);

void print_singly_list(const SinglyList *list);

#endif //SINGLY_LINKED_LIST_H
