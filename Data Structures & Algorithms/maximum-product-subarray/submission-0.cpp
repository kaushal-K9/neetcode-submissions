class Solution {
public:
    int ans = INT_MIN;

    pair<int, int> solve(int i, vector<int>& nums) {
        
        if (i == 0) {
            ans = nums[0];
            return {nums[0], nums[0]};
        }

        auto [prevMin, prevMax] = solve(i - 1, nums);

        int currMin = min ({nums[i], nums[i] * prevMin, nums[i] * prevMax});
        
        int currMax = max({nums[i], nums[i] * prevMin, nums[i] * prevMax});

        if (currMax > ans) ans = currMax;

        return {currMin, currMax};
    }
    int maxProduct(vector<int>& nums) {
        
        solve(nums.size() - 1, nums);

        return ans;
    }
};