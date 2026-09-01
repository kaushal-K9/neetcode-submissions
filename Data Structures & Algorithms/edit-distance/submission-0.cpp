class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s, string& t, int m, int n) {

        if(m == 0 || n == 0) {
            return m + n;
        }

        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        if (s[m - 1] == t[n - 1]) {
            return dp[m][n] = solve(s, t, m - 1, n - 1);
        } else {
            int insert = 1 + solve(s, t, m, n - 1);
            int del = 1 + solve(s, t, m - 1, n);
            int replace = 1 + solve(s, t, m - 1, n - 1);

            return dp[m][n] = min({insert, del, replace});
        }

        return -1;
    }
    int minDistance(string s, string t) {
        int m = s.length();
        int n = t.length();

        dp = vector<vector<int>> (m + 1, vector<int>(n + 1, -1));

        return solve(s, t, m, n);
    }
};