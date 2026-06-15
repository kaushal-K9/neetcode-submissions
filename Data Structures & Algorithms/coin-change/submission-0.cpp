class Solution {
public:
    int solve(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {

        if (i == 0) {
            if (amount % coins[i] == 0) return amount / coins[i];
            else return 1e9;
        }

        if (dp[i][amount] != -1) return dp[i][amount];

        int notTake = solve(coins, i - 1, amount, dp);

        int take = INT_MAX;

        if (coins[i] <= amount) {
            take = 1 + solve(coins, i, amount - coins[i], dp);
        }

        return dp[i][amount] = min(notTake, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();

        vector<vector<int>> dp (n, vector<int>(amount + 1, -1));

        int ans = solve(coins, n - 1, amount, dp);

        if (ans >= 1e9) return -1;
        
        return ans;
    }
};