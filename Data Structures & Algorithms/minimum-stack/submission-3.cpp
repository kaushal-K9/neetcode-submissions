class MinStack {
public:
    MinStack() {
        
    }

    stack<pair<int, int>> st;
    int min;
    
    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
            min = value;
        } else if (st.top().second > value) {
            min = value;
            st.push({value, value});
        } else {
            st.push({value, st.top().second});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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