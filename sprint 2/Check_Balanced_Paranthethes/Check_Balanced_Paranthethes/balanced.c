//
// Created by Youssef Abbas on 31/03/2023.
//

#include "balanced.h"
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
    int8_t flag = NOT_USED;
    // check if expression is empty or not
    if (sizeof(*expression) == 0)
        return flag;


    createEmptyStack(&stk);
    // loop for each expression and append parentheses only and ignore operand
    while (expression[i]!= '\0') {

        // check for parentheses
        if(expression[i] == '{' || expression[i] == '('){
            push(&stk, expression[i]);
            flag = NOT_USED;// there is parentheses but not balanced
        }
        if(expression[i] == '}' || expression[i] ==')'){
            int8_t stackStatus;
            uint8_t temp;
            stackStatus = pop(&stk, &temp);
            if((stackStatus != -2) && (((temp+1) == expression[i])||((temp+2) == expression[i]))){
                flag = BALANCED;
            }else{
                flag = NOT_BALANCED;
            }

        }
        i++;
    }
    return flag;
}