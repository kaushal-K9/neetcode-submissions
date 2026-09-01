class Solution {
public:
    int minDistance(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                } else if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }   
            }
        }

        return dp[m][n];
    }
};