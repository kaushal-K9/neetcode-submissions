class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;

        //find the row where target may exist
        while(l <= r) {
            int mid = l + (r - l)/ 2;

            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        int row = r;
        if (row < 0) return false;
        l = 0;
        r = matrix[0].size() - 1;

        while(l <= r) {
            int mid = l + (r - l)/ 2;

            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};