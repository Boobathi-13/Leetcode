/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int n, int target, int* returnSize) {
    *returnSize = 2;
    int* arr = (int*)malloc(2*sizeof(int));
    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            if((nums[i]+nums[j]) == target) {
                arr[0] = i;
                arr[1] = j;
                break;
            }
        }
    }
    return arr;
}