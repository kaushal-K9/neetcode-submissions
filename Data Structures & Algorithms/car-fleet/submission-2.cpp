class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        int n = position.size();

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), greater<>());

        stack<double> st;

        for (int i = 0; i < n; i++) {
            
            double maxtime = cars[i].second;

            if (!st.empty() && maxtime <= st.top()) continue;

            st.push(maxtime);

        }

        return st.size();
    }
};
