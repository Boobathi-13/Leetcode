int compare(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int firstMissingPositive(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int i = 0;
    while (i < numsSize && nums[i] <= 0) i++;
    if (i >= numsSize) return 1;
    
    int temp = 1;
    if (temp != nums[i]) return temp;
    
    temp++;
    i++;
    
    while (i < numsSize) {
        if (nums[i] == temp - 1) {
            i++;
            continue;
        }
        else if (nums[i] != temp) return temp;
        else {
            temp++;
        }
        i++;
    }
    return temp;
}