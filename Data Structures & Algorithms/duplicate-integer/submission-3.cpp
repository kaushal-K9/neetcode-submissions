class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto& n : nums) {
            if (mp.find(n) != mp.end()) return true;
            else mp[n]++; 
        }

        return false;
    }
};