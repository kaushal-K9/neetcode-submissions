class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m*n - 1;

        while (l <= r) {
            int mid = l + (r-l)/2;

            int row = mid/n;
            int col = mid%n;

            if (target == matrix[row][col]) {
                return true;
            } else if (target > matrix[row][col]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};