class Solution {
public:
    bool solve(string& s, int i, int j) {

        if (i >= j) return true;

        // if (t[i][j] != -1) return t[i][j];

        if (s[i] == s[j]) {
            return solve(s, i + 1, j - 1);
        }

        return false;
    }
    int countSubstrings(string s) {
        
        int n = s.length();
        int count = 0;

        // vector<vector<int>> t(n, vector<int>(n,-1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};