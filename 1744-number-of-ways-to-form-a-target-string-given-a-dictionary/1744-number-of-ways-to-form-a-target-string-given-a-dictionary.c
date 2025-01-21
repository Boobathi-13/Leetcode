int numWays(char** words, int wordsSize, char* target) {  
    int m = strlen(words[0]); // Length of each word  
    int n = strlen(target);   // Length of the target  

    // Count occurrences of each character at each position  
    long long count[26][m];  
    memset(count, 0, sizeof(count));  

    for (int j = 0; j < wordsSize; j++) {  
        for (int i = 0; i < m; i++) {  
            count[words[j][i] - 'a'][i]++;  
        }  
    }  

    // dp[i][j] will store the number of ways to form target[0:i] using the first j columns  
    long long dp[n + 1][m + 1];  
    memset(dp, 0, sizeof(dp));  
    dp[0][0] = 1; // One way to form an empty target using no columns  

    for (int j = 0; j < m; j++) {  
        for (int i = 0; i <= n; i++) {  
            // Carry forward the previous value (not using column j)
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % 1000000007;  

            // Use column j if possible
            if (i < n && count[target[i] - 'a'][j] > 0) {  
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * count[target[i] - 'a'][j]) % 1000000007;  
            }  
        }  
    }  

    return dp[n][m];  
}
