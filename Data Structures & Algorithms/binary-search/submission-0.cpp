class Solution {
public:
    int solve(vector<int>& nums, int l, int r, int target) {
        if (l > r) return -1;

        int mid = l + (r-l)/2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return solve(nums, l , mid - 1, target);
        } else {
            return solve(nums, mid + 1, r, target);
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        return solve(nums, l, r, target);
    }
};