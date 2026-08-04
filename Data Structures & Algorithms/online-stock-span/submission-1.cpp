class StockSpanner {
private:
    // Pairs' key is price and its value is span
    stack< pair<int, int> > myStack;

public:
    StockSpanner() {}
    
    int next(int price) {
        // Span starts at 1 since we're including the current day
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