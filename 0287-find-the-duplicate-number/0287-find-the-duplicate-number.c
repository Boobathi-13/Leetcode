int findDuplicate(int* nums, int n) {
    int* arr = (int*)calloc(n,(sizeof(int)));
    for(int i = 0; i<n; i++) {
        arr[nums[i]]++;
        if(arr[nums[i]]>1) {
            free(arr);
            return nums[i];
        }
    }
    free(arr);
    return n;
}