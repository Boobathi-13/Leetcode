int solve(int i, int j, int m, int n, int** grid, int dp[][n]){
    if(i>=m || j>=n || grid[i][j]==1) return 0; // Out of bounds or obstacle
    if(i==m-1 && j==n-1) return 1; // reached destination 
    if (dp[i][j] != -1) return dp[i][j];  // Return cached result
    return dp[i][j] = solve(i+1, j, m, n, grid, dp) + solve(i, j+1, m, n, grid, dp);
}

int uniquePathsWithObstacles(int** grid, int m, int* obstacleGridColSize) {
    int n = *obstacleGridColSize;
    int dp[m][n];
    memset(dp, -1, sizeof(dp));
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0; // No path, if start or end is blocked
    
    int result = solve(0, 0, m, n, grid, dp);

    // Print the DP table
    printf("DP Table:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) {
                printf(" X "); // Indicate unvisited cells
            } else {
                printf("%2d ", dp[i][j]);
            }
        }
        printf("\n");
    }

    return result;
}