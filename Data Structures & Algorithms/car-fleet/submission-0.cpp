class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> v;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            v.push_back({position[i], time});
        }

        sort(v.begin(), v.end(), greater<>());

        stack<double> st;

        for (int i = 0; i < n; i++) {

            double t = v[i].second;

            if (!st.empty() && t <= st.top()) continue;

            st.push(t);
        }

        return st.size();
    }
};