class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int dp[][] = new int[n][n];

        // Initialize the first row of dp with the values of the first row of the matrix
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Build the dp array row by row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int down = matrix[i][j] + dp[i - 1][j];
                int leftDiagonal = (j > 0) ? matrix[i][j] + dp[i - 1][j - 1] : Integer.MAX_VALUE;
                int rightDiagonal = (j < n - 1) ? matrix[i][j] + dp[i - 1][j + 1] : Integer.MAX_VALUE;
                dp[i][j] = Math.min(down, Math.min(leftDiagonal, rightDiagonal));
            }
        }

        // Find the minimum value in the last row of dp
        int minPathSum = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            minPathSum = Math.min(minPathSum, dp[n - 1][j]);
        }

        return minPathSum;
    }
}