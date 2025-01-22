int solve(int i, int j, int m, int n, int** gird, int dp[][n]){
    if(i>=m || j>=n || gird[i][j]==1) return 0; // Out of bounds or obstacle
    if(i==m-1 && j==n-1) return 1; // reached destination 
    if (dp[i][j] != -1) return dp[i][j];  // Return cached result
    return dp[i][j] = solve(i+1, j, m, n, gird, dp) + solve(i, j+1, m, n, gird, dp);
}

int uniquePathsWithObstacles(int** gird, int m, int* obstacleGridColSize) {
    int n = *obstacleGridColSize;
    int dp[m][n];
    memset(dp, -1, sizeof(dp));
    if (gird[0][0] == 1 || gird[m - 1][n - 1] == 1) return 0; // No path, if start or end is blocked
    return solve(0,0,m,n,gird,dp);
}