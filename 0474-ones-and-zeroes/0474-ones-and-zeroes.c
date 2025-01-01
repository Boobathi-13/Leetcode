// Function to count 0's and 1's in a string
void countZerosAndOnes(char *str, int *zeros, int *ones) {
    *zeros = 0;
    *ones = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0') (*zeros)++;
        else if (str[i] == '1') (*ones)++;
    }
}

int findMaxForm(char **strs, int strsSize, int m, int n) {
    // Create a DP array
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp)); // Initialize all elements to 0

    for (int i = 0; i < strsSize; i++) {
        int zeros, ones;
        countZerosAndOnes(strs[i], &zeros, &ones); // Count 0's and 1's in the current string

        // Update the DP table from the back to avoid overwriting previous results
        for (int j = m; j >= zeros; j--) {
            for (int k = n; k >= ones; k--) {
                dp[j][k] = (dp[j][k] > dp[j - zeros][k - ones] + 1) 
                           ? dp[j][k] 
                           : dp[j - zeros][k - ones] + 1;
            }
        }
    }

    return dp[m][n];
}