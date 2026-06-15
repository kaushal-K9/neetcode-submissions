class Solution {
public:
    int n;

    bool solve(vector<int>& nums, int idx, int target, vector<vector<int>>& dp) {

        if (target == 0) return true;

        if (target < 0 || idx == n) return false;

        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }
        
        bool take = solve(nums, idx + 1, target - nums[idx], dp);

        bool skip = solve(nums, idx + 1, target, dp); 

        return dp[idx][target] = (take || skip);

    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int sum = 0;

        for (auto& num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) return false;

        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));

        return solve(nums, 0, sum / 2, dp);

    }
};