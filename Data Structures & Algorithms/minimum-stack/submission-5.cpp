using namespace std;

class MinStack {

private:
    stack<int> stk; // has name "stk" since we can't name a stack "stack"
    stack<int> min_stack; 

public:
    MinStack() {}
    
    void push(int val) {
        // have to push val to stack no matter what
        stk.push(val);

        // check if min_stack has a minimum value already in there
        if(!(min_stack.empty())){
            // if the new value being pushed is less than or equal to the top value in min_stack we push it
            if(val <= min_stack.top()){
                min_stack.push(val);
            }
        }
        else{
            min_stack.push(val);
        }

    }
    
    void pop() {
        if(stk.top() == min_stack.top()){
            stk.pop();
            min_stack.pop();
        }
        else{
            stk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stack.top(); 
    }
};
