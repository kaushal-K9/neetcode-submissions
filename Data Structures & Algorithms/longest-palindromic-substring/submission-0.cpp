class Solution {
public:

    bool solve(string& s, int i, int j, vector<vector<int>>& dp) {

        if (i >= j) return 1;
        
        //using i >= j instead of i > j,
        //results in one less function call for odd length
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = solve(s, i + 1, j - 1, dp);

        }

        dp[i][j] = 0;
        return dp[i][j];
    }

    string longestPalindrome(string s) {

        
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int maxLen = INT_MIN;
        int sp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j ++) {
                if (solve(s, i, j, dp)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};