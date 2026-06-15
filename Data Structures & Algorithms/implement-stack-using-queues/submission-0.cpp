class MyStack {
public:
    MyStack() {
        
    }

    //to store all elements as stack
    queue<int> que1;

    //to push new elements into
    queue<int> que2;
    
    void push(int x) {
        que2.push(x);

        while(!que1.empty()) {
            que2.push(que1.front());
            que1.pop();
        }

        swap(que1, que2);
    }
    
    int pop() {
        int x = que1.front();
        que1.pop();
        return x;
    }
    
    int top() {
        return que1.front();
    }
    
    bool empty() {
        return que1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */