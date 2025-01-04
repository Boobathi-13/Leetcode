void help(char** grid, int row, int col, int x, int y) {

    grid[x][y] = '0';

    if (x - 1 >= 0 && grid[x - 1][y] == '1')
        help(grid, row, col, x - 1, y);
    if (x + 1 < row && grid[x + 1][y] == '1')
        help(grid, row, col, x + 1, y);
    if (y - 1 >= 0 && grid[x][y - 1] == '1')
        help(grid, row, col, x, y - 1);
    if (y + 1 < col && grid[x][y + 1] == '1')
        help(grid, row, col, x, y + 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {

    int row, col;

    row = gridSize;
    col = *gridColSize;

    int ans = 0;

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            if (grid[i][j] == '1') {
                help(grid, row, col, i, j);
                ans++;
            }
        }
    }

    return ans;

}