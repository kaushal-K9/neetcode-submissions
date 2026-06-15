class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int maxarea = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                int el_idx = st.top(); st.pop();
                int nse = i;
                int pse = st.empty()? -1 : st.top();
                maxarea = max(maxarea, (arr[el_idx] * (nse - pse -1)));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int el_idx = st.top(); st.pop();
            int nse = n;
            int pse = st.empty()? -1 : st.top();
            maxarea = max(maxarea, (arr[el_idx] * (nse - pse -1)));
        }

        return maxarea;
    }
};
