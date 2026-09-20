class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int leftMax = height[l];
        int rightMax = height[r];
        int result = 0;

        while (l < r) {
            if (leftMax < rightMax) {
                l += 1;
                leftMax = max(leftMax, height[l]);
                result += leftMax - height[l];
            } else {
                r -= 1;
                rightMax = max(rightMax, height[r]);
                result += rightMax - height[r];
            }
        }

        return result;
    }
};