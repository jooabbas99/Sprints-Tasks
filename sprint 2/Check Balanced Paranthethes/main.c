#include <stdio.h>
#include "stack.h"
#include <stdint.h>
#include <stdlib.h>


int main() {
    ST_stack_t stk;
    uint8_t tempData;
    //1. Create an empty stack
    createEmptyStack(&stk);
    //2. Push 5 different characters to the stack
    push(&stk,2);
    push(&stk,3);
    push(&stk,5);
    push(&stk,10);
    push(&stk,20);
//    3. Print all stack data
    printStack(&stk);
//    4. Pop one character from the stack
    pop(&stk,&tempData);
    printf(("%u\n"),tempData);
//    5. Print the stack's top

    getStackTop(&stk,&tempData);
    printf(" %d \n",tempData);
//    6. Print all stack data
    printStack(&stk);
//    7. Push another 7 different characters to the stack
    push(&stk,20);
    push(&stk,30);
    push(&stk,50);
    push(&stk,100);
    push(&stk,200);
    push(&stk,20);
    push(&stk,30);

//    8. Print the stack's top
    getStackTop(&stk,&tempData);
    printf(" %d \n",tempData);
//    9. Print all stack data
    printStack(&stk);
//    10. Pop 4 characters from the stack
    pop(&stk,&tempData);
    printf(" %d \n",tempData);
    pop(&stk,&tempData);
    printf(" %d \n",tempData);
    pop(&stk,&tempData);
    printf(" %d \n",tempData);
    pop(&stk,&tempData);
    printf(" %d \n",tempData);
//    11. Print the stack's top
    getStackTop(&stk,&tempData);
    printf(" %d \n",tempData);
//    12. Print all stack data
    printStack(&stk);
//    13. Pop 7 more times from the stack
    pop(&stk,&tempData);
    printf(" %d \n",tempData);
    pop(&stk,&tempData);
    printf(" %d \n",tempData);
    pop(&stk,&tempData);
    printf(" %d \n",tempData);
    pop(&stk,&tempData);
    printf(" %d \n",tempData);
    pop(&stk,&tempData);
    printf(" %d \n",tempData);
    pop(&stk,&tempData);
    printf(" %d \n",tempData);
    pop(&stk,&tempData);
    printf(" %d \n",tempData);

//    14. Print the stack's top
    getStackTop(&stk,&tempData);
    printf(" %d \n",tempData);
//    15. Print all stack data
    printStack(&stk);



    return 0;
}
