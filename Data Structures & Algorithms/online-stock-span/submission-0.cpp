class StockSpanner {
public:
    // Pairs' key is price and its value is span
    stack< pair<int, int> > myStack;

    StockSpanner() {

    }
    
    int next(int price) {
        
        int span = 1;

        while( !myStack.empty() && myStack.top().first <= price ){
            span += myStack.top().second;
            myStack.pop();
        }
        
        myStack.push( pair{price, span} );

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */