class FreqStack {

// Create a hashmap that will have a number as its key and its count as the value
// In every pop() we check which number has the greatest value
// Then, we iterate through freqStack in reverse order with a for loop
//  and using an if loop to check if the value matches. We'll erase the first
//  occurence of said value

public:
    vector<int> freqStack;
    unordered_map<int, int> myHM;   

    FreqStack() {    }
    
    void push(int val) {
        freqStack.push_back(val);    
        myHM[val]++;

    }
    
    int pop() {
        int maxValue = 0;
        for(auto const& [key, val] : myHM){
            if( val > maxValue ) maxValue = val;
        }

        int keyOfGreatest = -1;
        for(int j = freqStack.size() - 1 ; j >= 0 ; j--){
            if( myHM[freqStack[j]] == maxValue ) {
                keyOfGreatest = freqStack[j];
                freqStack.erase( freqStack.begin() + j ); 
                myHM[keyOfGreatest]--; 
                break;
            }
        }


        return keyOfGreatest;

    }
};