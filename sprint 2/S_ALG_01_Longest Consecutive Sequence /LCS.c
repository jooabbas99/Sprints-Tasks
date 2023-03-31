//
// Created by Youssef Abbas on 29/03/2023.
//

#include "LCS.h"
#include "sort.h"
#include <stdint.h>
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS){
    /* Description:
         * - This function takes a reference to an array,
         * - array size, and
         * - reference to store the size of the LCS
         * - Using the insertion sort algorithm
         * - The function will search for the LCS in the array and
         * - stores its size
         * Return:
         * - returns -1 if the array is empty
         * - returns -2 if the array size is 0 or >10
         * - returns -3 if there is no LCS,
         * (i.e all array elements are not consecutive at all)
         * - returns 0 otherwise
    */
    // Check if the array is empty
    if (arraySize == 0) {
        return -1;
    }

    // Check if the array size is within the range
    if (arraySize == 0 || arraySize > 10) {
        return -2;
    }


    // sort array
    insertionSort(array,arraySize);

    //LCS
    uint8_t lcsCount = 1,maxCount = 1;
    for (int i = 1; i < arraySize; i++) {
        if(array[i] == (array[i-1] + 1)){
            lcsCount ++;
            if (lcsCount > maxCount) {
                maxCount = lcsCount;
            }
        } else{
            lcsCount = 1;
        }
    }
    if(maxCount == 1)
        return -3;
    *sizeofLCS = maxCount;
    return 0;
    //

}