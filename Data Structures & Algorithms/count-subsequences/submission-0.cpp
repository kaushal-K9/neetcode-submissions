class Solution {
public:
    int m, n;   
    vector<vector<int>> dp;

    int solve(string& s, string& t, int i, int j) {

        if (j == n) {
            return 1;
        }

        if (i == m && j < n) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int take = 0;
        int skip = 0; 
        int not_match = 0;

        if (s[i] == t[j]) {
            take = solve(s, t, i + 1, j + 1);
            skip = solve(s, t, i + 1, j);
        } else {
            not_match = solve(s, t, i + 1, j);
        }

        return dp[i][j] = take + skip + not_match;

    }

    int numDistinct(string s, string t) {
        m = s.length();
        n = t.length();

        dp = vector<vector<int>>(m, vector<int>(n, -1));

        return solve(s, t, 0, 0);    
    }
};