class Solution {
public:
    int solve(vector<int>& nums, int i, int currsum, int target, 
    unordered_map<string, int>& mp) {

        if (i == nums.size()) {
            if (currsum == target) {
                return 1;
            } else {
                return 0;
            }
        }

        string key = to_string(i) + "_" + to_string(currsum);

        if (mp.count(key)) {
            return mp[key];
        }

        int plus = solve(nums, i + 1, currsum + nums[i], target, mp);
        int minus = solve(nums, i + 1, currsum - nums[i], target, mp);

        return mp[key] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        unordered_map<string, int> mp;

        int currsum = 0;

        return solve(nums, 0, currsum, target, mp);
    }
};