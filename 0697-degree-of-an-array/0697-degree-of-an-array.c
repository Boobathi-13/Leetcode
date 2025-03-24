#include <stdio.h>
#include <limits.h>

#define MAX_NUM 50000  // Given constraint for the maximum number

int findShortestSubArray(int* nums, int numsSize) {
    int freq[MAX_NUM + 1] = {0};  // Frequency of each number
    int first[MAX_NUM + 1];       // First occurrence index
    int last[MAX_NUM + 1];        // Last occurrence index
    
    int degree = 0, minLen = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];

        // If first occurrence, store the index
        if (freq[num] == 0) {
            first[num] = i;
        }
        
        last[num] = i;  // Update last occurrence
        freq[num]++;    // Increase frequency

        // Update degree of the array
        if (freq[num] > degree) {
            degree = freq[num];
        }
    }

    // Find the shortest subarray with the same degree
    for (int i = 0; i <= MAX_NUM; i++) {
        if (freq[i] == degree) {
            int length = last[i] - first[i] + 1;
            if (length < minLen) {
                minLen = length;
            }
        }
    }

    return minLen;
}