class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> mp;

        for (int i = 0; i < nums.size(); i++) {
            
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            //Checking the complement before inserting the 
            //current value ensures correctness even with duplicates.
            mp[nums[i]] = i;
        }

        return {};
    }
};
