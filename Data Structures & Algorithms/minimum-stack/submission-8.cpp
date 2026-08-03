class MinStack {
public:
    
    long long min = LLONG_MAX; 
    stack<long long> st;

    MinStack() {
        
    }
    
    void push(int value) {
        if (st.empty()) {
            min = value;
            st.push(value);
        } else if (value < min) {
            //we do not push the min on stack
            st.push(2LL*value - min);
            min = value;
        } else {
            st.push(value);
        }
    }
    
    void pop() {
        if (st.empty()) return;

        if (st.top() < min) {
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