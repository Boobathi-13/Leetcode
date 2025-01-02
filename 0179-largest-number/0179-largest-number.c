#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to compare two numbers represented as strings
int compare(const char *a, const char *b) {
    char ab[30], ba[30];
    sprintf(ab, "%s%s", a, b); // Concatenate a + b
    sprintf(ba, "%s%s", b, a); // Concatenate b + a
    return strcmp(ba, ab); // Reverse order for descending sort
}

char* largestNumber(int* nums, int numsSize) {
    if (numsSize == 0) {
        return strdup("0"); // If the input is empty, return "0"
    }
    
    // Allocate memory for string versions of numbers
    char** strNums = malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        strNums[i] = malloc(12 * sizeof(char)); // Maximum 10 digits + 1 for '\0'
        sprintf(strNums[i], "%d", nums[i]); // Convert number to string
    }
    
    // Manual sorting (bubble sort) using the custom comparator
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (compare(strNums[j], strNums[j + 1]) > 0) {
                // Swap strNums[j] and strNums[j + 1]
                char* temp = strNums[j];
                strNums[j] = strNums[j + 1];
                strNums[j + 1] = temp;
            }
        }
    }
    
    // If the largest number is "0", return "0" (handles cases like [0, 0])
    if (strcmp(strNums[0], "0") == 0) {
        for (int i = 0; i < numsSize; i++) {
            free(strNums[i]); // Free allocated memory
        }
        free(strNums);
        return strdup("0");
    }
    
    // Concatenate all strings to form the largest number
    size_t totalLength = 0;
    for (int i = 0; i < numsSize; i++) {
        totalLength += strlen(strNums[i]);
    }
    
    char* result = malloc((totalLength + 1) * sizeof(char)); // +1 for '\0'
    result[0] = '\0'; // Initialize as an empty string
    
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strNums[i]); // Concatenate each string
        free(strNums[i]); // Free the string memory
    }
    
    free(strNums); // Free the array of string pointers
    return result;
}
