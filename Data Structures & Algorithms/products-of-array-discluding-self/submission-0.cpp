class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> result(n,1);

        for (int i = 1; i < n; ++i) {
            result[i] = nums[i-1]*result[i-1];
        }

        int temp = 1;

        for (int i = n-1; i > 0; --i) {
            temp *= nums[i];
            result[i-1] *= temp;
        }

        return result;
    }
};
