//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.
//Example:
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns -3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns -2.
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> s_min;
    MinStack() {
        
    }
    
    void push(int x) {
        if (!s_min.empty()) {
            int t = s_min.top();
            if (t < x) {
                s_min.push(t);
            }
            else {
                s_min.push(x);
            }
        }
        else {
            s_min.push(x);
        }
        s.push(x);
    }
    
    void pop() {
        if (!s.empty())
            s.pop();
        if (!s_min.empty())
            s_min.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
