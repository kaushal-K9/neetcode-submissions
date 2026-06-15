class Solution {
public:
    int rob(vector<int>& nums) {

        int rob1 = 0;
        int rob2 = 0;

        int prev1 = 0;
        int prev2 = 0;

        int temp = 0;

        int n = nums.size();

        if (n == 1) return nums[0];

        //[...rob2, rob1, temp,...]
        for (int i = 0; i < nums.size() - 1; i++) {
            temp = nums[i];
            temp = max(temp + rob2, rob1);
            rob2 = rob1;
            rob1 = temp;
        }
        
        temp = 0;

        //[...prev2, prev1, temp...]
        for (int i = 1; i < nums.size(); i++) {
            temp = nums[i];
            temp = max(temp + prev2, prev1);
            prev2 = prev1;
            prev1 = temp;
        }

        return max(rob1, prev1);
    }
};