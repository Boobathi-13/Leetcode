// Helper function for the top-down DP approach
int dp(int left, int i, int numsSize, int* nums, int* multipliers, int m, int** memo) {
    // If all operations are used, return 0
    if (i == m) {
        return 0;
    }

    // If already calculated, return the stored result
    if (memo[left][i] != -1) {
        return memo[left][i];
    }

    // Calculate right index
    int right = numsSize - 1 - (i - left);

    // Option 1: Take the leftmost number
    int leftScore = nums[left] * multipliers[i] + dp(left + 1, i + 1, numsSize, nums, multipliers, m, memo);

    // Option 2: Take the rightmost number
    int rightScore = nums[right] * multipliers[i] + dp(left, i + 1, numsSize, nums, multipliers, m, memo);

    // Store and return the maximum score
    memo[left][i] = (leftScore > rightScore) ? leftScore : rightScore;
    return memo[left][i];
}

// Main function to find the maximum score
int maximumScore(int* nums, int numsSize, int* multipliers, int multipliersSize) {
    int m = multipliersSize;

    // Create memoization table initialized to -1
    int** memo = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        memo[i] = (int*)malloc((m + 1) * sizeof(int));
        for (int j = 0; j <= m; j++) {
            memo[i][j] = -1;
        }
    }

    // Call the recursive DP function
    int result = dp(0, 0, numsSize, nums, multipliers, m, memo);

    // Free allocated memory
    for (int i = 0; i <= m; i++) {
        free(memo[i]);
    }
    free(memo);

    return result;
}