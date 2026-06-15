class Solution {
public:
    int n;
    int m;

    void dfs (int row, int col, vector<vector<char>>& grid) {

        if (row >= m || row < 0 || col >= n || col < 0 || grid[row][col] != '1') {
            return;
        }

        grid[row][col] = 'v';

        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        
        m = grid.size();
        n = grid[0].size();

        int islands = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '1') {
                    dfs(row, col, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};