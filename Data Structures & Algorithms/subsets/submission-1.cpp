class Solution {
public:
    vector<vector<int>> result;

    void solve(int idx, vector<int>& nums, vector<int>& temp) {
        if (idx >= nums.size()) {
            result.push_back(temp);
            return;
        }

        //include this element in our choice
        temp.push_back(nums[idx]);
        solve(idx + 1, nums, temp);

        //exclude this element from our choice
        temp.pop_back();
        solve(idx + 1, nums, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;

        solve(0, nums, temp);

        return result;
    }
};