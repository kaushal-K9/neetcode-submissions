class Solution {
public:
    int ROW;
    int COL;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int r, int c, int prevVal) {

        if (r < 0 || c < 0 || r == ROW || c == COL ||
        matrix[r][c] <= prevVal) {
            return 0;
        } 

        if (dp[r][c]) {
            return dp[r][c];
        }

        //default value for each is 1
        int res = 1;

        res = max(res, 1 + dfs(matrix, r + 1, c, matrix[r][c]));
        res = max(res, 1 + dfs(matrix, r, c + 1, matrix[r][c]));
        res = max(res, 1 + dfs(matrix, r - 1, c, matrix[r][c]));
        res = max(res, 1 + dfs(matrix, r, c - 1, matrix[r][c]));

        return dp[r][c] = res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        ROW = matrix.size();
        COL = matrix[0].size();

        dp = vector<vector<int>>(ROW, vector<int>(COL, 0));

        int LIP = INT_MIN;

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                LIP = max(LIP, dfs(matrix, r, c, INT_MIN));
            }
        }

        return LIP;
    }
};