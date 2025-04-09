//
// Created by tech4life on 05/04/25.
//

#include "singly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct SNode SNode;

struct SNode {
    void *value;
    SNode *next;
};

struct SinglyList {
    SNode *head;
    SNode *tail;
    size_t length;

    void (*print)(const SinglyList *list);
};

static SNode *singly_list_node_create(void *value) {
    SNode *node = malloc(sizeof(SNode));

    node->value = value;
    node->next = NULL;
    return node;
}

static void print_int_list(const SinglyList *list) {
    const SNode *current = list->head;

    while (current) {
        printf("%d ", *(int *) current->value);
        current = current->next;
    }
}

SinglyList *singly_list_create(void) {
    SinglyList *list = malloc(sizeof(SinglyList));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->print = print_int_list;

    return list;
}

void singly_list_destroy(SinglyList *list) {
    SNode *current = list->head;

    while (current) {
        SNode *next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void singly_list_prepend(SinglyList *list, void *value) {
    SNode *node = singly_list_node_create(value);

    if (is_singly_list_empty(list)) list->tail = node;
    else node->next = list->head;;

    list->head = node;
    list->length++;
}

void singly_list_append(SinglyList *list, void *value) {
    SNode *node = singly_list_node_create(value);

    if (is_singly_list_empty(list)) list->head = node;
    else list->tail->next = node;

    list->tail = node;
    list->length++;
}

SNode *singly_list_traverse_to_index(const SinglyList *list, const size_t index) {
    SNode *node = list->head;
    for (size_t i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

void singly_list_insert(SinglyList *list, const size_t index, void *value) {
    if (index >= list->length) return singly_list_append(list, value);
    if (index == 0) return singly_list_prepend(list, value);

    SNode *node = singly_list_node_create(value);
    SNode *leader = singly_list_traverse_to_index(list, index - 1);

    node->next = leader->next;
    leader->next = node;
    list->length++;
}

void singly_list_remove(SinglyList *list, const size_t index) {
    if (index >= list->length) return;

    SNode *to_remove = NULL;
    if (index == 0) {
        to_remove = list->head;
        list->head = list->head->next;

        if (list->length == 1) list->tail = NULL;
    } else {
        SNode *leader = singly_list_traverse_to_index(list, index - 1);
        to_remove = leader->next;
        leader->next = to_remove->next;

        if (index == list->length - 1) list->tail = leader;
    }

    free(to_remove);
    list->length--;
}

void singly_list_reverse(SinglyList *list) {
    if (is_singly_list_empty(list)) return;

    SNode *prev = NULL;
    SNode *current = list->head;
    list->tail = list->head;

    while (current) {
        SNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
}

bool is_singly_list_empty(const SinglyList *list) {
    return !list->head;
}

void print_singly_list(const SinglyList *list) {
    list->print(list);
}
