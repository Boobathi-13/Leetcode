// int maximumCount(int* nums, int n) {
//     int pos = 0, neg = 0;
//     for(int i=0; i<n; i++){
//         if(nums[i]==0) continue;
//         else if(nums[i]>0) pos++;
//         else neg++;
//     }
//     return (pos>=neg) ? pos : neg;
// }


int findFirstPositive(int* nums, int n) {
    int low = 0, high = n - 1, posIndex = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > 0) {
            posIndex = mid; // Found a positive number, move left
            high = mid - 1;
        } else {
            low = mid + 1; // Move right
        }
    }
    return posIndex;
}

int findLastNegative(int* nums, int n) {
    int low = 0, high = n - 1, negIndex = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < 0) {
            negIndex = mid; // Found a negative number, move right
            low = mid + 1;
        } else {
            high = mid - 1; // Move left
        }
    }
    return negIndex;
}

int maximumCount(int* nums, int n) {
    int firstPositive = findFirstPositive(nums, n);
    int lastNegative = findLastNegative(nums, n);
    int positiveCount = (n - firstPositive); // Count of positives
    int negativeCount = (lastNegative + 1); // Count of negatives
    return (positiveCount >= negativeCount) ? positiveCount : negativeCount;
}