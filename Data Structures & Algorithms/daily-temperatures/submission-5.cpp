class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> answer(n, 0);

        if (n == 1) return answer;

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(i);
                answer[i] = 0;
            } else if (temperatures[i] < temperatures[st.top()]) {
                answer[i] = st.top() - i;
                st.push(i);
            } else {
                while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    answer[i] = 0;
                    st.push(i);
                } else {
                    answer[i] = st.top() - i;
                    st.push(i);
                }
            }
        }

        return answer;
    }
};