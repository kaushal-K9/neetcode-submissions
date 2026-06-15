class Solution {
public:
    int m;
    int n;
    int area;

    int dfs (int row, int col, vector<vector<int>>& grid) {

        if (row >= m || row < 0 || col >= n || col < 0 || grid[row][col] != 1) {
            return 0;
        }

        grid[row][col] = 2;

        return 1 + (dfs(row + 1, col, grid) +
        dfs(row - 1, col, grid) +
        dfs(row, col + 1, grid) +
        dfs(row, col - 1, grid) );
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();

        int islands = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    area = dfs(row, col, grid);
                    islands = max(islands, area);
                    area = 0;
                }
            }
        }

        return islands;
    }
};

