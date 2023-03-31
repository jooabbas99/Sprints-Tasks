//
// Created by Youssef Abbas on 29/03/2023.
//

#include "sort.h"
#include <stdint.h>
#include <stdio.h>


int8_t insertionSort(int32_t *array, uint8_t arraySize){
    /* Description:
        * - This function takes a reference to an array of integers
        * - Sorts the array in ascending order
        * - Using the insertion sort algorithm
        * Return:
        * - returns -1 if the array is empty
        * - returns -2 if the array size is 0 or >10
        * - returns 0 if sorting is done without errors
    */
    // Check if the array is empty
    if (arraySize == 0) {
        return -1;
    }
    // Check if the array size is within the range

    if(arraySize > 10 || arraySize < 0)
        return -2;
    // Insertion sort algorithm

    int32_t temp;
    for (uint8_t i = 1; i < arraySize; i++) {
        temp = array[i];
        uint8_t j = i;
        while (j > 0 && array[j-1] > temp) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = temp;
    }
    return 0;

}

void printArray(int32_t *array, uint8_t arraySize){
    /* Description:
     * - This function takes a reference to an array of integers
     * - Prints all array elements
     * Return:
     * - Nothing to return
    */
    if (arraySize == 0) {
        printf("array is empty");
        return;
    }
    printf("Print array, with #%d elements \n",arraySize);
    for(int i = 0; i < arraySize;i++)
        printf("%d \n",array[i]);
}

