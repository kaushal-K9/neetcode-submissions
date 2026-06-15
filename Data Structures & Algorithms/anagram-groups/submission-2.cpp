class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        vector<int> freq(26, 0);
        unordered_map<string, vector<string>> mp;

        for (auto& s : strs) {
            for (auto& c : s) {
                freq[c - 'a']++;
            }

            string temp;

            for(int i = 0; i < 26; i++) {
                while (freq[i] != 0) {
                    temp += 'a' + i;
                    freq[i]--;
                }
            }

            mp[temp].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& i : mp) {
            result.push_back(i.second);
        }

        return result;
    }
};