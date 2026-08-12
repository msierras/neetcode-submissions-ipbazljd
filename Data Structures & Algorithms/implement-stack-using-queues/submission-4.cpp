class MyStack {
public:
    queue<int> myQueue;
    MyStack() {}
    
    void push(int x) {
        myQueue.push(x);
    }
    
    int pop() {
        // Create another queue and while myQueue != myQueue.back we push to the new queue then set our current queue to that value
        queue<int> temp;

        int popped = myQueue.back();
        int sizeQ = myQueue.size() - 1;

        for(int i = 0; i < sizeQ; i++){
            temp.push( myQueue.front() );
            myQueue.pop();
        }

        myQueue = temp;

        return popped;
    }
    
    int top() {
        return myQueue.back();
    }
    
    bool empty() {
        return myQueue.empty();
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