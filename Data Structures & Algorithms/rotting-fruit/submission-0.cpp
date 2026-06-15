class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        int timestep = 0;

        vector<pair<int, int>> dirs = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty() && fresh > 0) {
            int sz = q.size();

            bool spread = false;


            for (int i = 0; i < sz; i++) {

                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= m || nr < 0 || nc >= n || nc < 0 || grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;
                    spread = true;
                    fresh--;
                    q.push({nr, nc});
                }
            }

            if (!spread && fresh > 0) return -1;

            timestep++;
            
        }

        if (fresh == 0) return timestep;

        return -1;
    }
};