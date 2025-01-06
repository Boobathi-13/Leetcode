int dfs(int** grid, int i, int j, int rows, int cols) {
    // Base case: out of bounds or water
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
        return 0;
    }

    // Mark the cell as visited
    grid[i][j] = 0;

    // Calculate area by recursively exploring neighbors
    int area = 1;
    area += dfs(grid, i + 1, j, rows, cols); // Down
    area += dfs(grid, i - 1, j, rows, cols); // Up
    area += dfs(grid, i, j + 1, rows, cols); // Right
    area += dfs(grid, i, j - 1, rows, cols); // Left

    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int maxArea = 0;

    // Traverse the grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) { // Found an island
                int area = dfs(grid, i, j, gridSize, gridColSize[i]);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }

    return maxArea;
}
