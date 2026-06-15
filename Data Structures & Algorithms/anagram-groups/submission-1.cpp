class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();

        vector<int> freq(26, 0);

        vector<vector<string>> result;

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < n; ++i) {

            for (auto &c : strs[i]) {
                freq[c - 'a']++;
            }

            string temp; 

            for (int j = 0; j < 26; ++j) {
                while (freq[j] != 0) {
                    temp += ('a' + j);
                    freq[j]--;
                }
            }

            mp[temp].push_back(strs[i]);

        }

        for (auto &i : mp) {
            result.push_back(i.second);
        }

        return result;

    }
};
