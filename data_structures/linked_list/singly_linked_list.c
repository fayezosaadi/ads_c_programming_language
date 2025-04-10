//
// Created by tech4life on 05/04/25.
//

#include "singly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    void *value;
    Node *next;
};

struct SList {
    Node *head;
    Node *tail;
    size_t length;

    void (*print_node)(const void *value);
};

static Node *node_create(void *value) {
    Node *node = malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;
    return node;
}

SList *list_create(void (*print_func)(const void *value)) {
    SList *list = malloc(sizeof(SList));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->print_node = print_func;

    return list;
}

void list_destroy(SList *list) {
    Node *current = list->head;

    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void list_prepend(SList *list, void *value) {
    Node *node = node_create(value);

    if (is_list_empty(list)) list->tail = node;
    else node->next = list->head;;

    list->head = node;
    list->length++;
}

void list_append(SList *list, void *value) {
    Node *node = node_create(value);

    if (is_list_empty(list)) list->head = node;
    else list->tail->next = node;

    list->tail = node;
    list->length++;
}

Node *list_traverse_to_index(const SList *list, const size_t index) {
    Node *node = list->head;
    for (size_t i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

void list_insert(SList *list, const size_t index, void *value) {
    if (index >= list->length) return list_append(list, value);
    if (index == 0) return list_prepend(list, value);

    Node *node = node_create(value);
    Node *leader = list_traverse_to_index(list, index - 1);

    node->next = leader->next;
    leader->next = node;
    list->length++;
}

void list_remove(SList *list, const size_t index) {
    if (index >= list->length) return;

    Node *to_remove = NULL;
    if (index == 0) {
        to_remove = list->head;
        list->head = list->head->next;

        if (list->length == 1) list->tail = NULL;
    } else {
        Node *leader = list_traverse_to_index(list, index - 1);
        to_remove = leader->next;
        leader->next = to_remove->next;

        if (index == list->length - 1) list->tail = leader;
    }

    free(to_remove);
    list->length--;
}

void list_reverse(SList *list) {
    if (is_list_empty(list)) return;

    Node *prev = NULL;
    Node *current = list->head;
    list->tail = list->head;

    while (current) {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
}

bool is_list_empty(const SList *list) {
    return !list->head;
}

void print_list(const SList *list) {
    const Node *current = list->head;

    while (current) {
        list->print_node(current->value);
        current = current->next;
    }
    printf("\n");
}
