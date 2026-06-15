class Solution {
public:

    int n;

    int solve(vector<int>& nums, int idx, int previdx, vector<vector<int>>& dp) {

        if (idx == n) return 0;

        if (dp[idx][previdx + 1] != -1) return dp[idx][previdx + 1];

        int take = 0;

        if (previdx == -1 || nums[idx] > nums[previdx]) {
            take = 1 + solve(nums, idx + 1, idx, dp);
        }

        int skip = solve(nums, idx + 1, previdx, dp);

        return dp[idx][previdx + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>> dp (n, vector<int>(n + 1, -1));

        return solve(nums, 0, -1, dp);
    }
};