class Solution {
public:
    bool jump(vector<int>& nums, int idx, int end, vector<int>& pathexist) {

        if (idx == end) return true;

        if (nums[idx] == 0) return pathexist[idx] = 0;

        if (pathexist[idx] != -1) return pathexist[idx];

        for (int i = 1; i <=nums[idx]; i++) {
            bool found = jump(nums, idx + i, end, pathexist);
            if (found) return pathexist[idx + i] = true;
        }

        return pathexist[idx] = 0;

    }
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;

        int n = nums.size();
        
        vector<int> pathexist(n, -1);
        
        return jump(nums, 0, n - 1, pathexist);
    }
};