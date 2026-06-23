class Solution {
public:
    vector<vector<int>> result;

    void makeSubset(vector<int>& nums, int i, vector<int>& temp) {

        if (i >= nums.size()) {
            result.push_back(temp);
            return;
        }

        //include the current element in our choice and move ahead
        temp.push_back(nums[i]);
        makeSubset(nums, i + 1, temp);

        //do not pick the current element and move ahead
        temp.pop_back();
        makeSubset(nums, i + 1, temp);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;

        makeSubset(nums, 0, temp);

        return result;
    }
};