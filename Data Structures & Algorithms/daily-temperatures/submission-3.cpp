class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> result(n);
        
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            } //only the most recent max stays, and no two same recent maxs

            if (st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top() - i;
            }

            st.push(i);
        }

        return result;
    }
};
