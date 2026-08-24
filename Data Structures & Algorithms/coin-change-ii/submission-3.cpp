class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<unsigned int> dp(amount + 1, 0);

        dp[0] = 1;

        //each place is a sum of previous d[j]
        // and current d[j - coin]
        for (auto coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];
    }
};