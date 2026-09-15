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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();

        //store the sorted starts
        sort(intervals.begin(), intervals.end(), [](const Interval& a, 
        const Interval& b){
            return a.start < b.start;
        });
        
        vector<int> start;

        for (const Interval& interval : intervals) {
            start.push_back(interval.start);
        }

        //store the sorted ends
        vector<int> end;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, 
        const Interval& b){
            return a.end < b.end;
        });

        for (const Interval& interval : intervals) {
            end.push_back(interval.end);
        }

        int s = 0;
        int e = 0;

        int count = 0;
        int res = 0;

        while (s < n) {
            if (start[s] < end[e]) {
                s++;
                count++;
            } else if (start[s] >= end[e]) {
                e++;
                count--;
            }

            res = max(res, count);
        }

        return res;
    }
};
