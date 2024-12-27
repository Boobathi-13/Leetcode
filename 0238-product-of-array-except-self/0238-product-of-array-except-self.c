int* productExceptSelf(int* nums, int n, int* returnSize) {
    int* ans = (int*) malloc(sizeof(int) * n);
    *returnSize = n;
    int flag = 0;
    int product = 1;
    for(int i=0; i<n; i++){
        if(nums[i]!=0)
            product *= nums[i];
        else flag++;
    }
    for(int i=0; i<n; i++){
        if(flag>1 || flag==1 && nums[i]!=0) ans[i]=0;
        else if(flag==1 && nums[i]==0) ans[i] = product;
        else ans[i] = product/nums[i];
    }
    return ans;
}