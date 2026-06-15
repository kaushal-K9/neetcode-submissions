class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_map<int, bool> m;

       for(auto n : nums) {
        if (m.find(n) != m.end()){
            return true;
        }
        else {
            m[n] = true;
        }
       }
       return false;
    }
};