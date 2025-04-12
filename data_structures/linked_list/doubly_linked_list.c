//
// Created by tech4life on 05/04/25.
//

#include "doubly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    void *value;
    Node *next;
    Node *prev;
};

struct List {
    Node *head;
    Node *tail;
    size_t length;

    void (*print_node)(const void *value);
};

static Node *node_create(void *value) {
    Node *node = malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

List *list_create(void (*print_func)(const void *value)) {
    List *list = malloc(sizeof(List));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->print_node = print_func;

    return list;
}

void list_destroy(List *list) {
    Node *current = list->head;

    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void list_prepend(List *list, void *value) {
    Node *node = node_create(value);

    if (is_list_empty(list)) {
        list->tail = node;
    } else {
        list->head->prev = node;
        node->next = list->head;
    }

    list->head = node;
    list->length++;
}

void list_append(List *list, void *value) {
    Node *node = node_create(value);

    if (is_list_empty(list)) list->head = node;
    else {
        list->tail->next = node;
        node->prev = list->tail;
    }

    list->tail = node;
    list->length++;
}

Node *list_traverse_to_index(const List *list, const size_t index) {
    Node *node = list->head;
    for (size_t i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

void list_insert(List *list, const size_t index, void *value) {
    if (index >= list->length) return list_append(list, value);
    if (index == 0) return list_prepend(list, value);

    Node *node = node_create(value);
    Node *leader = list_traverse_to_index(list, index - 1);
    Node *follower = leader->next;

    follower->prev = node;
    node->next = follower;
    node->prev = leader;
    leader->next = node;
    list->length++;
}

void list_remove(List *list, const size_t index) {
    if (index >= list->length) return;

    Node *to_remove = NULL;
    if (index == 0) {
        to_remove = list->head;
        list->head = to_remove->next;

        if (list->head) list->head->prev = NULL;
        else list->tail = NULL;
    } else {
        Node *leader = list_traverse_to_index(list, index - 1);
        to_remove = leader->next;
        leader->next = to_remove->next;

        if (index == list->length - 1) list->tail = leader;
        else to_remove->next->prev = leader;
    }

    free(to_remove);
    list->length--;
}

void list_reverse(List *list) {
    if (is_list_empty(list)) return;

    Node *current = list->head;
    list->head = list->tail;
    list->tail = current;

    while (current) {
        Node *temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp;
    }
}

bool is_list_empty(const List *list) {
    return !list->head;
}

void print_list(const List *list) {
    const Node *current = list->head;

    while (current) {
        list->print_node(current->value);
        current = current->next;
    }
    printf("\n");
}
