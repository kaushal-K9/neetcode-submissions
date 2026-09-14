class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int i = 1;
        vector<int> L = intervals[0]; //last_interval

        while (i < n) {

            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            int last_end = L[1];

            if (last_end <= curr_start) {
                L = intervals[i];
                i++;
            } else if (last_end >= curr_end) {
                L = intervals[i];
                i++;
                count++;
            } else if (last_end < curr_end) {
                i++;
                count++;
            }
        }

        return count;
    }
};