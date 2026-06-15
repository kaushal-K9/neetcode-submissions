class MinStack {
public:
    MinStack() {
        
    }

    stack<long long> st;
    long long min;
    
    void push(int value) {
        if (st.empty()) {
            st.push(value);
            min = value;
        } else if (value > min) {
            st.push(value);
        } else {
            st.push(2LL*value - min);
            min = value;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        else if (st.top() < min) {
            min = 2LL*min - st.top();
            st.pop();
        } else {
            st.pop();
        }
    }
    
    int top() {
        if (st.top() < min) {
            return min;
        } else {
            return st.top();
        }
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */