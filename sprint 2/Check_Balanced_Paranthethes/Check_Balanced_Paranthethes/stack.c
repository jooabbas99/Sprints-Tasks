//
//  stack.c
//  Check_Balanced_Paranthethes
//
//  Created by Youssef Abbas on 28/03/2023.
//

#include "stack.h"
void createEmptyStack(ST_stack_t *stack){
    stack->top = EMPTY_STACK_TOP;
    for(short i = 0 ; i < STACK_SIZE ; i++)
        stack->elements[i] = 0;
}

int8_t push(ST_stack_t *stack, uint8_t data){
    if(isFull(stack))
        return STACK_FULL;
    stack->elements[++stack->top] = data;
    return STACK_OTHER;
}

int8_t pop(ST_stack_t *stack, uint8_t *data){
    if(isEmpty(stack))
        return STACK_EMPTY;
    *data = stack->elements[stack->top--];
    return STACK_OTHER;
}

int8_t printStack(ST_stack_t *stack){
    if (isEmpty(stack))
        return STACK_EMPTY;
    for (short i = stack->top ; i>=0 ; i--)
        printf("%d\n",stack->elements[i]);
    if (isFull(stack))
        return STACK_FULL;
    return STACK_OTHER;
}

int8_t getStackTop(ST_stack_t *stack, uint8_t *topData){
    if(isEmpty(stack))
        return STACK_EMPTY;
    *topData = stack->elements[stack->top];
    return STACK_OTHER;
}

int8_t isEmpty(ST_stack_t *stack){
    if (stack->top == EMPTY_STACK_TOP)
        return STACK_FULL;
    return STACK_OTHER;
}
int8_t isFull(ST_stack_t *stack){
    if(stack->top == STACK_SIZE-1)
        return STACK_EMPTY;
    return STACK_OTHER;
}
