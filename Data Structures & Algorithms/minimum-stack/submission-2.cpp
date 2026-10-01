class MinStack {
    stack<int> s;
    stack<int> t;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(!t.empty()){
            t.push(min(t.top(),val));
        }else{
            t.push(val);
        }
    }
    
    void pop() {
        s.pop();
        t.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return t.top();
    }
};
