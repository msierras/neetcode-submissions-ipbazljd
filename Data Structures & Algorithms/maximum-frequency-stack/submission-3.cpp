class FreqStack {
public:
    // We have a HashMap where key is the value and key is its number of occurrences
    // For each item we push onto the freqStack we increment that key-pair

    // When popping, we go through the hashmap to find the largest occurrence number
    // Then we do a reverse for loop and if the hashmap[element] is equal to the largest occurrence number
    //  we can pop that value and decrement it on the hashmap 

    vector<int> freqStack;
    unordered_map<int, int> myHm;

    FreqStack() {}
    
    void push(int val) {
        freqStack.push_back(val);
        myHm[val]++;
    }
    
    int pop() {
        
        int largestOccur = INT_MIN;
        int toReturn;
        // First, a for loop that will determine the largest occurrence value
        for( const auto & [ key, value ] : myHm){
            if( value >= largestOccur ) largestOccur = value;
        }

        cout << largestOccur;

        for(int i = freqStack.size() - 1; i > 0; i--){
            if( myHm[ freqStack[i] ] == largestOccur ){
                toReturn = freqStack[i];
                myHm[ freqStack[i] ]--;
                freqStack.erase( freqStack.begin() + i );
                return toReturn;
            }
        }


  
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */