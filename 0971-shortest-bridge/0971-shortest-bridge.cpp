class Solution {
public:
    void dfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || grid[i][j] == 0)
            return;
        vis[i][j] = 1;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int k = 0; k < 4; k++) {
            int r = i + dir[k].first;
            int c = j + dir[k].second;
            dfs(vis, grid, r, c);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(vis, grid, i, j);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) {
                    q.push({0, {i, j}});
                }
            }
        }

        
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int cost = top.first;
            int row = top.second.first;
            int col = top.second.second;

            for (int k = 0; k < 4; k++) {
                int r = row + dir[k].first;
                int c = col + dir[k].second;
                if (r < 0 || c < 0 || r >= m || c >= n || vis[r][c])
                    continue;

                if (grid[r][c] == 1) {
                   
                    return cost;
                } else if (grid[r][c] == 0) {
                    
                    vis[r][c] = 1;
                    q.push({cost + 1, {r, c}});
                }
            }
        }

        return -1;
    }
};