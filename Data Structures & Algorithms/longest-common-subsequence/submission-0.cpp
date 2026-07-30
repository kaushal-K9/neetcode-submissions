class Solution {
public:
    int m, n;
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& t) {

        if (i >= m || j >= n) {
            return 0;
        }

        if (t[i][j] != -1) return t[i][j];

        if (s1[i] == s2[j]) {
            return t[i][j] = 1 + solve(s1, s2, i + 1, j + 1, t);
        }

        return t[i][j] = max(solve(s1, s2, i + 1, j, t), 
                    solve(s1, s2, i, j + 1, t));
    }
    int longestCommonSubsequence(string s1, string s2) {
        m = s1.length();
        n = s2.length();

        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));
        return solve(s1, s2, 0, 0, t);
    }
};