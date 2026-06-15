class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();

        vector<vector<int>> dp (n, vector<int>(amount + 1, 0));

        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0) {
                dp[0][amt] = amt / coins[0];
            } 
            else 
                dp[0][amt] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int amt = 0; amt <= amount; amt++) {

                int notTake = dp[i - 1][amt];

                int take = 1e9;

                if (coins[i] <= amt) {
                    take = 1 + dp[i][amt - coins[i]];
                }

                dp[i][amt] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][amount];

        if (ans >= 1e9) return -1;

        return ans;
    }
};