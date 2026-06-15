class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];

        int curSum = 0;

        for (int i = 0; i < n; i++) {
            curSum = max(curSum, 0);
            curSum += nums[i];
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};
