class Solution {
public:
    int m;
    int n;

    void dfs(vector<vector<char>>& board, int row, int col, 
        vector<vector<int>>& visited) {

        if (row < m && row >= 0 && col < n && col >= 0 && board[row][col] == 'O'
         && visited[row][col] == 0) {

            visited[row][col] = 1;

            vector<pair<int, int>> dirs = {
                {1, 0}, {-1, 0}, {0, 1}, {0, -1}
            };

            for (auto [dr, dc] : dirs) {
                int nr = row + dr;
                int nc = col + dc;

                dfs(board, nr, nc, visited);
            }
        }

        return;
    }

    void solve(vector<vector<char>>& board) {
        
        m = board.size();
        n = board[0].size();

        vector<vector<int>> visited(m, vector<int> (n, 0));

        //visit top and bottom row for exposed 'O's
        for (int j = 0; j < n; j++) {

            dfs(board, 0, j, visited);
            dfs(board, m - 1, j, visited);

        }

        //for leftmost and rightmost column containing exposed O's
        for (int i = 0; i < m; i++) {

            dfs(board, i, 0, visited);
            dfs(board, i, n - 1, visited);

        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }

    }
};