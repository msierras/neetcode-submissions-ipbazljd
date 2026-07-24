class MinStack {
private:
    std::stack<int> stk;
    std::stack<int> minStk;

public:


    MinStack() {

    }
    

    // When min is empty we push val
    // When min is not empty, check if min.top() or val is smaller
    //  and push that smaller value back on min

    void push(int val) {
        stk.push(val);

        if( minStk.empty() ) {
            minStk.push(val);
        }
        else{
            val = min(val, minStk.top());
            minStk.push( val );
        }

    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
