/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const Interval& a, 
        const Interval& b){
            return a.start < b.start;
        });

        int i = 0;
        int j = 1;

        while (j < n) {
            if (intervals[i].end <= intervals[j].start) {
                i = j;
                j++;
            } else if (intervals[i].end > intervals[j].start) {
                return false;
            }
        }

        return true;
    }
};
