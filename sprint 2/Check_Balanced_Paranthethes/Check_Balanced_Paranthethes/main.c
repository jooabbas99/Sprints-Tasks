//
//  main.c
//  Check_Balanced_Paranthethes
//
//  Created by Youssef Abbas on 28/03/2023.
//
#include "main.h"
int main(int argc, const char * argv[]) {
    unsigned char expression[ARR_SIZE];
    printf("enter expression #MAX is %d : ",ARR_SIZE);
    scanf("%s",&expression);
    printf("TEST expression : %d \n",isBalancedParanthethes(&expression));

    return 0;
}



void testStack(void){
    ST_stack_t stk;
    uint8_t tempData;
    //1. Create an empty stack
    createEmptyStack(&stk);
    //2. Push 5 different characters to the stack
    printf("%d\n",push(&stk,2));
    printf("%d\n",push(&stk,3));
    printf("%d\n",push(&stk,5));
    printf("%d\n",push(&stk,10));
    printf("%d\n",push(&stk,20));
    //    3. Print all stack data
    printStack(&stk);
    //    4. Pop one character from the stack
    printf("%d\n",pop(&stk,&tempData));
    printf(("%u\n"),tempData);
    //    5. Print the stack's top

    printf("%d\n",getStackTop(&stk,&tempData));
    printf("%d \n",tempData);
    //    6. Print all stack data
    printf("%d\n",printStack(&stk));
    //    7. Push another 7 different characters to the stack
    printf("%d\n",push(&stk,20));
    printf("%d\n",push(&stk,30));
    printf("%d\n",push(&stk,50));
    printf("%d\n",push(&stk,100));
    printf("%d\n",push(&stk,200));
    printf("%d\n",push(&stk,20));
    printf("%d\n",push(&stk,30));

    //    8. Print the stack's top
    printf("%d\n",getStackTop(&stk,&tempData));
    printf("%d \n",tempData);
    //    9. Print all stack data
    printStack(&stk);
    //    10. Pop 4 characters from the stack
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);
    //    11. Print the stack's top
    printf("%d\n",getStackTop(&stk,&tempData));
    printf("%d \n",tempData);
    //    12. Print all stack data
    printf("%d\n",printStack(&stk));
    //    13. Pop 7 more times from the stack
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);
    printf("%d\n",pop(&stk,&tempData));
    printf("%d \n",tempData);

    //    14. Print the stack's top
    getStackTop(&stk,&tempData);
    printf("%d \n",tempData);
    //    15. Print all stack data
    printStack(&stk);

}
