//
// Created by tech4life on 05/04/25.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Queue Queue;

Queue *queue_create(void);

void queue_destroy(Queue *queue);

void enqueue(Queue *queue, void *value);

void dequeue(Queue *queue);

void *peek(const Queue *queue);

bool is_queue_empty(const Queue *queue);

#endif //QUEUE_H
