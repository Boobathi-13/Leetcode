int triangularSum(int* nums, int n) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            nums[j] = nums[j] + nums[j+1];
            nums[j] %= 10;
        }
    }
    return nums[0];
}