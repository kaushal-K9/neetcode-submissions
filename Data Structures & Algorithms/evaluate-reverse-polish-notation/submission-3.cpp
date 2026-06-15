class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                int result;

                if (s == "-") result = a - b;
                if (s == "/") result = a / b;
                if (s == "*") result = a * b;
                if (s == "+") result = a + b;

                st.push(result);

            } else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};
