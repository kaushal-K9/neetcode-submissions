class Solution {
public:
    int n;
    vector<vector<int>> t;

    int solve(int i, vector<int>& coins, int amount) {
        if (amount == 0) return 1;

        if (i == n) return 0;

        if (t[i][amount] != -1) {
            return t[i][amount];
        }

        if (amount < coins[i]) {
            return t[i][amount] = solve(i + 1, coins, amount);
        }

        int take = solve(i, coins, amount - coins[i]);
        int skip = solve(i + 1, coins, amount);

        return t[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();

        t = vector<vector<int>>(n, vector<int>(amount + 1, -1));

        return solve(0, coins, amount);
    }
};
