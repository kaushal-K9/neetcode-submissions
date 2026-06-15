class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto& s : tokens) {

            if (s == "+" || s == "-" || s == "*" || s == "/") { 
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                char op = s[0];
                int result;

                if (op == '*') result = a * b;
                if (op == '+') result = a + b;
                if (op == '-') result = a - b;
                if (op == '/') result = a / b;

                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};