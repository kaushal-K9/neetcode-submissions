class Solution {
public:
    int solve(vector<int>& nums, int s, int n) {

        int rob1 = 0;
        int rob2 = 0;

        //[...rob2, rob1, temp,...]
        for (int i = s; i <= n; i++) {
            int temp = max(nums[i] + rob2, rob1);
            rob2 = rob1;
            rob1 = temp;
        }

        return rob1;
    }
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return nums[0];

        int steal_zeroth = solve(nums, 0, n - 2);
        int skip_zeroth = solve(nums, 1, n - 1);

        return max(steal_zeroth, skip_zeroth);
    }
};