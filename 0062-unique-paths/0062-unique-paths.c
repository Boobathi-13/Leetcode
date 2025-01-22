int solve(int i, int j, int m, int n, int dp[][n+1]) {
    if(i>=m || j>=n) return 0; // Out of bounds
    if(i==m-1 && j==n-1) return 1; // reached destination 
    if (dp[i][j] != -1) return dp[i][j];  // Return cached result
    return dp[i][j] = solve(i+1, j, m, n, dp) + solve(i, j+1, m, n, dp);
}

int uniquePaths(int m, int n) {
    int dp[m+1][n+1];
    memset(dp, -1, sizeof(dp));
    return solve(0,0,m,n,dp);
}