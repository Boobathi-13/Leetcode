class NeighborSum {

    private final int[] adjacentSums, diagonalSums;

    public NeighborSum(int[][] grid) {

        adjacentSums = new int[grid.length * grid.length];
        diagonalSums = new int[adjacentSums.length];

        for (int i = 0; i < grid.length; i++)
            for (int j = 0; j < grid[0].length; j++) {
                adjacentSums[grid[i][j]] = getAdjSum(grid, i, j);
                diagonalSums[grid[i][j]] = getDigSum(grid, i, j);
            }
    }

    private int getAdjSum(int[][] grid, int i, int j) {

        int sum = 0;
        if (i > 0) sum += grid[i - 1][j];
        if (i < grid.length - 1) sum += grid[i + 1][j];
        if (j > 0) sum += grid[i][j - 1];
        if (j < grid[0].length - 1) sum += grid[i][j + 1];

        return sum;
    }


    private int getDigSum(int[][] grid, int i, int j) {

        int sum = 0;
        if (i > 0 && j > 0) sum += grid[i - 1][j - 1];
        if (i > 0 && j < grid[0].length - 1) sum += grid[i - 1][j + 1];
        if (i < grid.length - 1 && j > 0) sum += grid[i + 1][j - 1];
        if (i < grid.length - 1 && j < grid[0].length - 1) sum += grid[i + 1][j + 1];

        return sum;
    }

    public int adjacentSum(int value) {
        return adjacentSums[value];
    }

    public int diagonalSum(int value) {
        return diagonalSums[value];
    }
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum obj = new NeighborSum(grid);
 * int param_1 = obj.adjacentSum(value);
 * int param_2 = obj.diagonalSum(value);
 */