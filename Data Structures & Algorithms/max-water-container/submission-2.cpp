class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() -1;

        int macs = 0;

        while (i < j) {
            macs = max(min(height[i], height[j]) * (j - i), macs);
            if (height[i] < height[j]) i++;
            else j--;
        }

        return macs;
    }
};