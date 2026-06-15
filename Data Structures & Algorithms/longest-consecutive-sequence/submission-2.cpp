class Solution {
public:
    bool ls(vector<int>& nums, int x) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if (n==0) return 0;
        int longest = 1;

        for (int i=0; i<n; ++i) {
            int cur = 1;
            int x = nums[i];
            
            while(ls(nums, x+1) == true) {
                cur+=1;
                x += 1;
            }

            longest = max(cur, longest);
        }

        return longest;
    }
};