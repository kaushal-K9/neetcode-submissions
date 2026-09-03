class Solution {
public:
    vector<vector<int>> dp{22, vector<int> (22, -1)};

    bool solve(int i, int j, string s, string p) {
        if (j == p.length()) {
            return i == s.length();
        }

        if (dp[i][j] != -1) return dp[i][j];

        bool first_char_matched = false;

        if (i < s.length() && (p[j] == s[i] || p[j] == '.')) {
            first_char_matched = true;
        }

        if (p[j + 1] == '*') {

            bool not_take = solve(i, j + 2, s, p);

            bool take = first_char_matched && solve(i + 1, j, s, p);

            return dp[i][j] = not_take || take;
        }

        return dp[i][j] = first_char_matched && solve(i + 1, j + 1, s, p);
    }

    bool isMatch(string s, string p) {
        return solve(0, 0, s, p);
    }
};