class Solution {
public:
    vector<vector<int>> result;

    void subset(vector<int>& nums, int start, vector<int>& temp) {
       result.push_back(temp);

       for (int idx = start; idx < nums.size(); idx++) {
            
            if (idx > start && nums[idx] == nums[idx - 1]) continue;
        
            temp.push_back(nums[idx]);
            subset(nums, idx + 1, temp);
            temp.pop_back();
       }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subset(nums, 0, temp);

        return result;
    }
};