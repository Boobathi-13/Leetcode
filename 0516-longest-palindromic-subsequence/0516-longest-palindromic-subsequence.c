int lps(int i, int j, char* s, int** dp){
    if (i > j) return 0; // Base case: If indices cross, no valid subsequence
    if (i == j) return 1; // Base case: A single character is a palindrome of length 1

    // If result is already computed, return it
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == s[j]) 
        dp[i][j] = 2 + lps(i + 1, j - 1, s, dp); // Case 1: Characters match, extend palindrome length by 2
    else 
        dp[i][j] = fmax(lps(i + 1, j, s, dp), lps(i, j - 1, s, dp)); // Case 2: Characters don't match, take the maximum of excluding either character
    
    return dp[i][j];
}

int longestPalindromeSubseq(char* s) {
    int n = strlen(s);

    // Dynamically allocate memory for dp table
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(n * sizeof(int)); // Allocate memory for each row
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1; // Initialize each cell to -1 (not computed)
        }
    }

    return lps(0, n-1, s, dp);
}