//
// Created by tech4life on 05/04/25.
//

#include "queue.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct QNode QNode;

struct QNode {
    void *value;
    QNode *next;
};

struct Queue {
    QNode *head;
    QNode *tail;
};

QNode *queue_node_create(void *value) {
    QNode *node = malloc(sizeof(QNode));
    node->value = value;
    node->next = NULL;

    return node;
}

Queue *queue_create(void) {
    Queue *queue = malloc(sizeof(Queue));
    queue->head = queue->tail = NULL;
    return queue;
}

void queue_destroy(Queue *queue) {
    while (!is_queue_empty(queue)) dequeue(queue);
    free(queue);
}

void enqueue(Queue *queue, void *value) {
    QNode *node = queue_node_create(value);

    if (is_queue_empty(queue)) queue->head = node;
    else queue->tail->next = node;

    queue->tail = node;
}

void dequeue(Queue *queue) {
    if (is_queue_empty(queue)) return;

    QNode *head = queue->head;
    queue->head = head->next;

    if (queue->head == NULL) queue->tail = NULL;

    free(head);
}

void *queue_peek(const Queue *queue) {
    if (is_queue_empty(queue)) return NULL;
    return queue->head->value;
}

bool is_queue_empty(const Queue *queue) {
    return queue->head == NULL;
}
