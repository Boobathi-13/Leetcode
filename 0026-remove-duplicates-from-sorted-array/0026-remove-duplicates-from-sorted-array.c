int removeDuplicates(int* nums, int n) {
    if(n==0) return 0;

    int j = 1;

    for(int i=1; i<n; i++){
        if(nums[j-1]!=nums[i]){
            nums[j]=nums[i];
            j++;
        }
    }
    return j;
}