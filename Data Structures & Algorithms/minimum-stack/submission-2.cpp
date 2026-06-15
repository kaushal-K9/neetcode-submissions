class MinStack {
public:
    MinStack() {
        
    }
    stack<long long> st;
    long long min = LLONG_MAX;
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            min = val;
        } else if (val < min) {
            long long to_push = 2LL * val - min; //first get what to push
            min = val;
            st.push(to_push);
        } else {
            st.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) return;

        if (min > st.top()) {
            min = 2LL * min - st.top();
            st.pop();
        } else {
            st.pop();
        }
    }
    
    int top() {
        if (min > st.top()) {
            return min;
        } else {
            return st.top();
        }
    }
    
    int getMin() {
        return min;
    }
};
