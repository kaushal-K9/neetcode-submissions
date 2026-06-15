class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int last_smallest = INT_MIN;
        int n = nums.size();
        if (n==0) return 0;
        sort(nums.begin(), nums.end());
        int longest = 1;
        int cur = 1;

        for (int i = 0; i < n; ++i) {
            if(nums[i] -1 == last_smallest) {
                cur += 1;
                last_smallest = nums[i];
            } else if (nums[i] != last_smallest) {
                last_smallest = nums[i];
                cur = 1;
            }

            longest = max(cur, longest);
        }

        return longest;
    }
};