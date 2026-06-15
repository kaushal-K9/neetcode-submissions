class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        //what if the array is only one element and that is negative
        //int maxSum = 0;
        int maxSum = nums[0];

        for (int i = 0; i < n; i++) {
            int curSum = 0;
            for (int j = i; j < n; j++) {
                curSum += nums[j];
                maxSum = max(maxSum, curSum);
            }
        }

        return maxSum;
    }
};
