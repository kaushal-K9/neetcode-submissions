class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto& c : s) {
            if (c == '{' || c == '[' || c == '(') {
                st.push(c);
            } else {
                if (st.empty()) return false; //closing should see an opening

                if (c == '}' && st.top() != '{') return false;
                if (c == ')' && st.top() != '(') return false;
                if (c == ']' && st.top() != '[') return false;
                
                st.pop(); //if no violation, we can pop
            }
        }

        return st.empty();
    }
};
