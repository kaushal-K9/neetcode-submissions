class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int i = 0;
        int j = 1;

        while (j < n) {
            vector<int> curr = intervals[i];
            vector<int> next = intervals[j];

            if (curr[1] <= next[0]) {
                i = j;
                j++;
            } else if (curr[1] > next[1]) {
                i = j;
                j++;
                count++;
            } else if (curr[1] <= next[1]) {
                j++;
                count++;
            }
        }

        return count;
    }
};