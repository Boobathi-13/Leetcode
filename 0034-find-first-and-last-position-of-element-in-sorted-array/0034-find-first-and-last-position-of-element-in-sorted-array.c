/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int n, int target, int* returnSize) {
    int* arr = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    arr[0] = -1;
    arr[1] = -1;
    // for(int i = 0; i<n; i++) {
    //     if(target == nums[i]){
    //         arr[0] = i;
    //         break;
    //     }
    // }
    // for(int i = n-1; i>=0; i--) {
    //     if(target == nums[i]) {
    //         arr[1] = i;
    //         break;
    //     }
    // }
    int left = 0, right = n - 1, mid;

    // Find the first occurrence
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            if (mid == 0 || nums[mid - 1] != target) {
                arr[0] = mid;
                break;
            } else {
                right = mid - 1; // Narrow search to the left
            }
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // Reset left and right for the last occurrence search
    left = 0;
    right = n - 1;

    // Find the last occurrence
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            if (mid == n - 1 || nums[mid + 1] != target) {
                arr[1] = mid;
                break;
            } else {
                left = mid + 1; // Narrow search to the right
            }
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return arr;
}