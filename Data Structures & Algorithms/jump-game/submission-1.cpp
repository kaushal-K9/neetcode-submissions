class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxReach = 0;
        int reach = 0;

        for (int i = 0; i < n; i++) {
            if (i <= maxReach) {
                reach = i + nums[i];
                maxReach = max(reach, maxReach); 
                if (maxReach >= n - 1) return true;
            } else break;
        }

        return false;

    }
};