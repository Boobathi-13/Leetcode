void getMaxNumber(int *nums, int size, int outsize, int *out) {
    int len = 0, i, k = size - outsize;
    out[0] = nums[0];
    for (i = 1; i < size; i++) {
        while (len >= 0 && k > 0 && nums[i] > out[len]) k--, len--;
        out[++len] = nums[i];
    }
}

int compareArr(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i;
    for (i = 0; i < nums1Size && i < nums2Size && nums1[i] == nums2[i]; i++);
    //if (i == nums1Size && i == nums2Size) return 0;
    if (i == nums1Size) return -1;
    if (i == nums2Size) return 1;
    return (nums1[i] - nums2[i]);
}

void merge(int* nums1, int nums1Size, int* nums2, int nums2Size, int *out) {
    int len = 0, i = 0, j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] > nums2[j]) out[len++] = nums1[i++];
        else if (nums1[i] < nums2[j]) out[len++] = nums2[j++];
        else if (compareArr(nums1 + i, nums1Size - i, nums2 + j, nums2Size - j) >= 0) out[len++] = nums1[i++];
        else out[len++] = nums2[j++];
    }
    while (i < nums1Size) out[len++] = nums1[i++];
    while (j < nums2Size) out[len++] = nums2[j++];
}

int compare(int *arr1, int *arr2, int len) {
    int i = 0;
    for (; i < len && arr1[i] == arr2[i]; i++);
    if (i < len) return arr1[i] - arr2[i];
    return 0;
}

int min(int x, int y) {return x <= y ? x: y;}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    int i = 0, j = 0;
    int *arr1, *arr2, *ans, *tmp;
    if (k <= 0) {
        *returnSize = 0;
        return NULL;
    }
    arr1 = malloc(sizeof(int) * (nums1Size + nums2Size));
    arr2 = arr1 + nums1Size;
    ans = malloc(sizeof(int) * k);
    tmp = malloc(sizeof(int) * k);
    for (j = 0; j < k; j++) ans[j] = 0;
    for (i = min(k, nums1Size); i >= 0; i--) {
        j = k - i;
        if (j > nums2Size) break;
        if (i > 0) getMaxNumber(nums1, nums1Size, i, arr1);
        if (j > 0) getMaxNumber(nums2, nums2Size, j, arr2);
        merge(arr1, i, arr2, j, tmp);
        if (compare(tmp, ans, k) > 0) {
            for (j = 0; j < k; j++) ans[j] = tmp[j];
        }
    }
    free(tmp);
    free(arr1);
    *returnSize = k; 
    return ans;
}