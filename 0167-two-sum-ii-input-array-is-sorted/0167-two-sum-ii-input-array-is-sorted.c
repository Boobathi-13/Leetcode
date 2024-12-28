/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int n, int target, int* returnSize) {
    *returnSize = 2;
    int* ans = (int*) malloc(sizeof(int)*2);
    for(int i=0; i<n; i++){
        int complement = target - nums[i];
        int low = i+1, high = n-1;
        while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid] == complement){
            ans[0] = i+1;
            ans[1] = mid+1;
            return ans;
        }
        else if(nums[mid]<complement) low = mid + 1;
        else high = mid - 1;
        }
    }
    return 0;
}