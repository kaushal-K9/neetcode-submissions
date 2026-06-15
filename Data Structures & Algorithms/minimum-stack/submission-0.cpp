class MinStack {
public:
    
    stack<long long> st;
    long long min_val = LLONG_MAX;

    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            min_val = val;
            st.push(val);
        } else {
            if (val < min_val) {
                long long push_val = 2LL*val - min_val;
                min_val = val;
                st.push(push_val);
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        if (min_val > top) {
            min_val = 2LL*min_val - top;
        }
    }
    
    int top() {
        if (min_val > st.top()) {
            return min_val;
        } else {
            return st.top();
        }
    }
    
    int getMin() {
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */