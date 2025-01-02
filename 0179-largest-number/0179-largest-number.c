#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom comparator for sorting strings
int compare(const void* a, const void* b) {
    char* str1 = *(char**)a;
    char* str2 = *(char**)b;
    
    // Concatenate both possible combinations
    char combo1[200], combo2[200];
    strcpy(combo1, str1);
    strcat(combo1, str2);
    
    strcpy(combo2, str2);
    strcat(combo2, str1);
    
    // Compare the two concatenated results
    return strcmp(combo2, combo1);  // Reverse order
}

char* largestNumber(int* nums, int numsSize) {
    // Allocate memory for string representation of numbers
    char** numStrs = (char**)malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        numStrs[i] = (char*)malloc(12 * sizeof(char));  // Enough for int as string
        sprintf(numStrs[i], "%d", nums[i]);
    }
    
    // Sort the string array using qsort and the custom comparator
    qsort(numStrs, numsSize, sizeof(char*), compare);
    
    // Handle edge case where the largest number is "0"
    if (strcmp(numStrs[0], "0") == 0) {
        free(numStrs);
        return "0";
    }
    
    // Concatenate sorted numbers into the result string
    char* result = (char*)malloc(numsSize * 12 * sizeof(char));
    result[0] = '\0';  // Initialize empty string
    for (int i = 0; i < numsSize; i++) {
        strcat(result, numStrs[i]);
        free(numStrs[i]);  // Free individual strings after concatenation
    }
    free(numStrs);
    
    return result;
}