class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n - 1;
        int maxarea = 0;

        while (i < j) {
            int height = min(heights[i], heights[j]);
            int width = j - i;

            int area = height * width;
            maxarea = max(maxarea, area);

            if (heights[i] > heights[j]) j--;
            else i++;
        }

        return maxarea;
    }
};
