class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<unordered_map<int, int>> dp(n + 1);

        //for no index included the dp index is 0,
        //ways to get sum 0 is just 1, by not including anything
        dp[0][0] = 1;

        //iterate over the index of nums
        for (int i = 0; i < n; i++) {
            for (auto& [curr_sum, count] : dp[i]) {
                dp[i + 1][curr_sum + nums[i]] += count;
                dp[i + 1][curr_sum - nums[i]] += count;
            }
        }

        return dp[n][target];
    }
};