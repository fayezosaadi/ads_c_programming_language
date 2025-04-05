//
// Created by tech4life on 05/04/25.
//

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Stack Stack;

Stack *stack_create(void);

void stack_destroy(Stack *stack);

void stack_push(Stack *stack, void *value);

void stack_pop(Stack *stack);

void *stack_peek(const Stack *stack);

bool is_stack_empty(const Stack *stack);

#endif //STACK_H
