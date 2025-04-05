//
// Created by tech4life on 05/04/25.
//

#include "stack.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

enum {
    INITIAL_STACK_CAPACITY = 128
};

struct Stack {
    void **data;
    size_t capacity;
    size_t length;
};

Stack *stack_create(void) {
    Stack *stack = malloc(sizeof(Stack));
    stack->length = 0;
    stack->capacity = INITIAL_STACK_CAPACITY;
    stack->data = (void **) calloc(stack->capacity, sizeof(void *));
    return stack;
}

void stack_destroy(Stack *stack) {
    if (!stack) return;
    free((void *) stack->data);
    free(stack);
}

void stack_push(Stack *stack, void *value) {
    stack->data[stack->length++] = value;
}

void stack_pop(Stack *stack) {
    stack->length--;
}

void *stack_peek(const Stack *stack) {
    const size_t index = stack->length - 1;
    return stack->data[index];
}

bool is_stack_empty(const Stack *stack) {
    return stack->length == 0;
}
