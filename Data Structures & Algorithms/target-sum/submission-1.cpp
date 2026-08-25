class Solution {
public:
    vector<vector<int>> dp;
    int S;

    int solve(vector<int>& nums, int i, int currsum, int target, 
    vector<vector<int>>& dp) {

        if (i == nums.size()) {
            if (currsum == target) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dp[i][currsum + S] != -1) {
            return dp[i][currsum + S];
        }

        int plus = solve(nums, i + 1, currsum + nums[i], target, dp);
        int minus = solve(nums, i + 1, currsum - nums[i], target, dp);

        return dp[i][currsum + S] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        S = accumulate(nums.begin(), nums.end(), 0);

        dp = vector<vector<int>>(n + 1, vector<int>(2*S + 1, -1));

        int currsum = 0;

        return solve(nums, 0, currsum, target, dp);
    }
};