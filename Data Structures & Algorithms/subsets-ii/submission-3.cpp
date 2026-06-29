class Solution {
public:
    vector<vector<int>> result;

    void genSub(vector<int>& nums, int idx, vector<int>& temp) {

        result.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {

            if (i > idx && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            genSub(nums, i + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());

        genSub(nums, 0, temp);

        return result;
    }
};