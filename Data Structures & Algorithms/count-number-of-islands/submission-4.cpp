class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        q.push({i, j});
        grid[i][j] = '0';

        int dRow[4] = {1, -1, 0, 0};
        int dCol[4] = {0, 0, 1, -1};

        while (!q.empty()) {

           pair<int, int> curr = q.front();
           q.pop();

           int r = curr.first;
           int c = curr.second;

           for (int k = 0; k < 4; k++) {

            int nr = r + dRow[k];
            int nc = c + dCol[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                grid[nr][nc] = '0';
                q.push({nr, nc});
            }
           }

        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                //is this node valid, untouched
                if (grid[i][j] == '1') {
                    count++;

                    //run a bfs and conquer island
                    bfs(i, j, grid);
                }
            }
        }

        return count;
    }
};

// 1 1 0 0 0
// 1 1 0 0 0 
// 0 0 1 0 0 
// 0 0 0 1 1 

//a non-zero node is discovered, make it zero 
//and add neighbor to queue

