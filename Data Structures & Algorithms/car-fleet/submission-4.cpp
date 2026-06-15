class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        if (n == 1) return 1;

        vector<pair<int, double>> t;

        for (int i = 0; i < n; i++) {
            double time = double(target - position[i]) / speed[i];
            t.push_back({position[i], time});
        }

        sort (t.begin(), t.end());

        int fleets = 0;
        double maxTime = 0; //for closest car to set it first

        for (int i = n - 1; i >= 0; i--) {
            if (t[i].second > maxTime) { //group based on maxTime, slowest car leads
                fleets++;
                maxTime = t[i].second;
            }
        }

        return fleets;    

    }
};