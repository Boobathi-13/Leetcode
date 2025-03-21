/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void merge(int* nums, int le, int m, int ri) {
    int n1 = m - le + 1;
    int n2 = ri - m;
    int l[n1], r[n2];

    for(int i = 0; i<n1; i++) l[i] = nums[le + i];
    for(int i = 0; i<n2; i++) r[i] = nums[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = le;
    while(i<n1 && j<n2) {
        if(l[i]<=r[j]) {
            nums[k] = l[i];
            i++;
        }
        else {
            nums[k] = r[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        nums[k] = l[i];
        i++;
        k++;
    }
    while(j<n2){
        nums[k] = r[j];
        j++;
        k++;
    }
}
void mergeSort(int* nums, int l, int r) {
    if(l<r) {
        int m = l + (r - l)/2;

        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }
}
int* sortArray(int* nums, int n, int* re) {
    *re = n;
    mergeSort(nums, 0, n-1);
    return nums;
}