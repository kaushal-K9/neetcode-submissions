class Solution {
public:
    vector<vector<string>> result;
    int n;

    void partit(string& s, int idx, vector<string>& curr) {

        if (idx == n) {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < n; i++) {

            if (isPalindrome(s, idx, i)) {
                
                curr.push_back(s.substr(idx, i - idx + 1));

                partit(s, i + 1, curr);

                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {

        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }

            l++; r--;
        }

        return true;
    }

    vector<vector<string>> partition(string s) {
        
        n = s.length();

        vector<string> curr;

        partit(s, 0, curr);

        return result;
    }
};