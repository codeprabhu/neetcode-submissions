class MinStack {
public:
    stack<int> s, mini;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        val = min(val, mini.empty() ? val: mini.top());
        mini.push(val);
    }
    
    void pop() {
        s.pop();
        mini.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini.top();
    }
};
