class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int i, int target, vector<int>& temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        } else if (target < 0 || i ==nums.size()) {
            return;
        }

        temp.push_back(nums[i]);
        solve(nums, i, target - nums[i], temp);
        
        temp.pop_back();
        solve(nums, i+1, target, temp);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<int> temp;
        
        solve(nums, 0, target, temp);

        return result;
    }
};
