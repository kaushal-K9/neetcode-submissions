class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto& c : tokens) {
            if (c == "+" || c == "*" || c == "/" || c == "-") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int result;
                char op = c[0];

                if (op == '*') result = a * b;
                if (op == '/') result = b / a;
                if (op == '-') result = b - a;
                if (op == '+') result = a + b;

                st.push(result);
            } else {
                st.push(stoi(c));
            }
        }

        return st.top();
    }
};