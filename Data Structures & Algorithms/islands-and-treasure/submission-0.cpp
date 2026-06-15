class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        if (grid.empty()) return;

        int m = grid.size();
        int n = grid[0].size();

        const int INF = 2147483647;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {

            pair<int, int> cell = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;
            
            for (auto [r, c] : dirs) {
                int nr = row + r;
                int nc = col + c;

                if (nr >= m || nr < 0 || nc >= n || nc < 0
                    || grid[nr][nc] != INF) continue;

                grid[nr][nc] = grid[row][col] + 1;

                q.push({nr, nc});
            }

        }
    }
};
