class Solution {
public:
    vector<vector<int>> result;
    int n;

    void permute(int idx, vector<int>& nums) {

        //nothing to swap with
        if (idx == n) {
            result.push_back(nums);
            return;
        }

        //avoid repetition by starting i from where idx has shifted to
        for (int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);

            permute(idx + 1, nums);

            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        permute(0, nums);
        
        return result;
    }
};