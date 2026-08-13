// A stack can only push at the end and pop at the end
// We want to create a queue which pushes at the end and pops the front
class MyQueue {
public:

    vector<int> myStack;

    MyQueue() {}
    
    void push(int x) {
        myStack.push_back(x);
    }
    
    int pop() {
        vector<int> temp;
        int popped = myStack[0];
        for(int i = 1; i < myStack.size(); i++){
            temp.push_back(myStack[i]);
        }

        myStack = temp;

        return popped;

    }
    
    int peek() {
        // First thought is to create a copy of myStack and keep popping it till its size is only 1, which at that point will be the "front" of the queue

        vector<int> temp;
        temp = myStack;

        while(temp.size() != 1){
            temp.pop_back();
        }

        return temp[temp.size() - 1];
    }       
    
    bool empty() {
        return myStack.empty();        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */