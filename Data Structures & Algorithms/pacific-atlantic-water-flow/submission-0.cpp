class Solution {
public:
    vector<pair<int, int>> dirs = {
        {1,0}, {-1, 0}, {0, 1}, {0, -1}
    };

    void DFS(vector<vector<int>>& heights, int i, int j, int prev,
             vector<vector<bool>>& visited) {

        if (i >= heights.size() || i < 0 || j >= heights[0].size() || j < 0 
            || visited[i][j] == 1) return;

        if (heights[i][j] < prev) return;

        visited[i][j] = 1;
        prev = heights[i][j];

        for (auto [dr, dc] : dirs) {
            int nr = i + dr;
            int nc = j + dc;

            DFS(heights, nr, nc, prev, visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> atlvis(m , vector<bool>(n, 0));
        vector<vector<bool>> pacvis(m , vector<bool>(n, 0));

        //top row:Pacific ocean access
        //bottom row: Atlantic ocean access
        for (int j = 0; j < n; j++) {
            DFS(heights, 0, j, INT_MIN, pacvis); //top row
            DFS(heights, m - 1, j, INT_MIN, atlvis); //bottom row
        }

        //leftcolumn: Pacific ocean access
        //rightcolumn: Atlantic ocean access
        for (int i = 0; i < m; i++) {
            DFS(heights, i, 0, INT_MIN, pacvis); //left col
            DFS(heights, i, n - 1, INT_MIN, atlvis); //right col
        }

        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacvis[i][j] && atlvis[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};