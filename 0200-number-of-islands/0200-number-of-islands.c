#include <stdbool.h>

void dfs(char** grid, int i, int j, int m, int n) {
    // Base case: Out of bounds or water ('0')
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;

    // Mark the current cell as visited by setting it to '0'
    grid[i][j] = '0';

    // Explore all 4 directions
    dfs(grid, i - 1, j, m, n); // Up
    dfs(grid, i + 1, j, m, n); // Down
    dfs(grid, i, j - 1, m, n); // Left
    dfs(grid, i, j + 1, m, n); // Right
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;          // Number of rows
    int n = *gridColSize;      // Number of columns
    int count = 0;             // Island count

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') { // Found an unvisited land cell
                dfs(grid, i, j, m, n); // Explore the entire island
                count++; // Increment the island count
            }
        }
    }
    return count;
}
