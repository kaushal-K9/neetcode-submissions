class Solution {
public:
    unordered_set<string> st;
    vector<int> dp = vector<int>(1001, -1);

    bool solve(int i, string& s) {
        
        if (i >= s.length()) {
            return dp[i] = 1;
        }

        if (dp[i] != -1) return dp[i];


        for (int l = 1; i + l <= s.length(); l++) {
            
            string temp = s.substr(i, l);

            if (st.find(temp) != st.end() && solve(i + l, s)) {
                return dp[i] = 1;
            }
        }

        return dp[i] = 0; 
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for (auto& word: wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};