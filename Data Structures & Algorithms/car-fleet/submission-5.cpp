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

        stack<double> st;

        for (int i = n - 1; i >= 0; i--) {

            if (st.empty()) st.push(t[i].second);
            else if (st.top() < t[i].second) st.push(t[i].second);

        }

        return st.size();

    }
};