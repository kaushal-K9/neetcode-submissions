class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int n = height.size();

        int i = 0;
        int j = n -1;

        while(i<j) {
            int ht = min(height[i], height[j]);
            int len = j - i;

            int area = ht*len;

            if(area > max) max = area;
            if(height[i]<height[j]) i++;
            else j--;
        }

        return max;
    }
};