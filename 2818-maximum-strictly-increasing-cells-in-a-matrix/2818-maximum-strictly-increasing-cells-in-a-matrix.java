class Solution {
    public int maxIncreasingCells(int[][] mat) {
        int n = mat.length; // Number of rows
        int m = mat[0].length; // Number of columns
        
        int[] rMax = new int[n]; // Maximum number of increasing cells in each row
        int[] cMax = new int[m]; // Maximum number of increasing cells in each column
        
        TreeMap<Integer, List<int[]>> map = new TreeMap<>(); // TreeMap to store positions based on values
        
        // Store positions for each value in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = mat[i][j];
                map.putIfAbsent(val, new ArrayList<>());
                map.get(val).add(new int[]{i, j});
            }
        }
        
        int[][] dp = new int[n][m]; // DP array to store intermediate results
        
        // Iterate through values in increasing order
        for (int value : map.keySet()) {
            List<int[]> positions = map.get(value); // Get positions for the current value
            
            // Update the current position result
            for (int[] pos : positions) {
                int row = pos[0];
                int col = pos[1];
                dp[row][col] = Math.max(rMax[row], cMax[col]) + 1;
            }
            
            // Update the maximum values for rows and columns
            for (int[] pos : positions) {
                int row = pos[0];
                int col = pos[1];
                rMax[row] = Math.max(rMax[row], dp[row][col]);
                cMax[col] = Math.max(cMax[col], dp[row][col]);
            }
        }
        
        int maxCells = 0; // Maximum number of increasing cells
        
        // Find the maximum value in the dp array
        for (int[] row : dp) {
            for (int cells : row) {
                maxCells = Math.max(maxCells, cells);
            }
        }
        
        return maxCells;
    }
}