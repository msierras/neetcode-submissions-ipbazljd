class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Question is asking for greatest profit that can be achieved in a SINGLE transaction!

        int left = 0;
        int right = 1;

        int res = 0;

        for(int right = 0; right < prices.size(); right++){

            if( prices[left] < prices[right] ){ // Only care when prices of left pointer is less than right pointer since that's the only time we can make a profit
                res = max(prices[right] - prices[left], res);   // Is current profit greater than all time profit?
            }
            else{   // If price at left pointer is greater than price at right pointer, set equal to right pointer
                left = right;
            }

        }

        return res;
    }
};
