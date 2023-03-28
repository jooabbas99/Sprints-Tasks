//
//  main.c
//  Check_Balanced_Paranthethes
//
//  Created by Youssef Abbas on 28/03/2023.
//

#include <stdio.h>
#include "stack.h"
void testStack(void);
int8_t isBalancedParanthethes(uint8_t *expression);
int main(int argc, const char * argv[]) {
    unsigned char expression[10];
    printf("enter expression #MAX is 10 : ");
    scanf("%s",&expression);
    printf("TEST expression : %d \n",isBalancedParanthethes(&expression));

    return 0;
}

int8_t isBalancedParanthethes(uint8_t *expression){
    /* Description:
     * - This function takes an expression array max 10 characters
     * - Checks if the parentheses are balanced or not
     * - Checks the following parentheses types {, }, (, ) only
     * Return:
     * - returns -2 if the neither of paranthethes is used
     * - returns -1 if the parentheses are not balanced
     * - returns 0 if the parentheses are balanced
     */
    ST_stack_t stk;//stack
    int8_t i = 0;//counter
    int8_t flag = -2;
    // check if expression is empty or not
    if (sizeof(*expression) == 0)
        return flag;
    

    createEmptyStack(&stk);
    // loop for each expression and append parentheses only and ignore operand
    while (expression[i]!= '\0') {
        
        // check for parentheses
        if(expression[i] == '{' || expression[i] == '('){
            push(&stk, expression[i]);
            flag = -1;// there is parentheses but not balanced
        }
        if(expression[i] == '}' || expression[i] ==')'){
            int8_t stackStatus;
            uint8_t temp;
            stackStatus = pop(&stk, &temp);
            if((stackStatus != -2) && (((temp+1) == expression[i])||((temp+2) == expression[i]))){
                flag = 0;
            }else{
                flag = -1;
            }
            
        }
        i++;
    }
    return flag;
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
