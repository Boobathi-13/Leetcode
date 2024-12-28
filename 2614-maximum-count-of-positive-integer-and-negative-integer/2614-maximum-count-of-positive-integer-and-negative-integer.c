int maximumCount(int* nums, int n) {
    int pos = 0, neg = 0;
    for(int i=0; i<n; i++){
        if(nums[i]==0) continue;
        else if(nums[i]>0) pos++;
        else neg++;
    }
    return (pos>=neg) ? pos : neg;
}