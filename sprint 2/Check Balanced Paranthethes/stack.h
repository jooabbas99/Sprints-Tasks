//
// Created by Youssef Abbas on 28/03/2023.
//

#ifndef CHECK_BALANCED_PARANTHETHES_STACK_H
#define CHECK_BALANCED_PARANTHETHES_STACK_H
#include <stdint.h>
#include <stdio.h>
#define STACK_SIZE 10
typedef struct {
    int8_t elements[STACK_SIZE];
    int8_t top;

} ST_stack_t;

void createEmptyStack(ST_stack_t *stack);

int8_t push(ST_stack_t *stack, uint8_t data);

int8_t pop(ST_stack_t *stack, uint8_t *data);

int8_t printStack(ST_stack_t *stack);

int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);

int8_t isEmpty(ST_stack_t *stack);
int8_t isFull(ST_stack_t *stack);
#endif //CHECK_BALANCED_PARANTHETHES_STACK_H
