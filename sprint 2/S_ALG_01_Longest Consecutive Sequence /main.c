#include <stdio.h>
#include "sort.h"
#include <stdint.h>
#include "LCS.h"
/*
Task Description
    The Longest Consecutive Subsequence(LCS) is a subset of the original array
    where the numbers are in sorted order,
    from lowest to highest, and are in consecutive, increasing order.
 */
#define MAX_ARR 50



int main() {
    // read from user
    int32_t array [MAX_ARR] ;
    uint8_t LCS, arrSize ;
    printf("How many numbers you wana to enter :");
    scanf("%d", &arrSize);
    for(int8_t i = 0 ; i<arrSize;i++){
        printf("Element %d :",i+1);
        scanf("%d",&array[i]);
    }
    // test sorting
    //    printf("flag : %d \n",insertionSort(array,arrSize));
    //    printArray(&array,arrSize);

    // test LCS
    printf("flag : %d\n", lcsGetSize(&array,arrSize,&LCS));
    printf("LCS : %d \n",LCS);
    printArray(&array,arrSize);

    return 0;
}
