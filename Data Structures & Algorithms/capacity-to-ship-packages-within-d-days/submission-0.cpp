class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // 
        
        // Upper bound is the sum of all weights in the ship
        int L = *max_element(weights.begin(), weights.end());
        int R = accumulate( weights.begin(), weights.end() , 0 );
        int res = R;

        while(L <= R){

            int currWeight = (L + R)/2;
            int currWeightTemp = currWeight;
            int numDays = 1;

            for(int i = 0; i < weights.size(); i++){
                // for each iteration, subtract currWeightTemp by current boat weight
                // If the subtraction results in anything less than 1 then increment numDays

                if( currWeightTemp - weights[i] < 0 ){
                    numDays++;
                    currWeightTemp = currWeight;

                    currWeightTemp -= weights[i];
                }
                else {
                    currWeightTemp -= weights[i];
                }

            }

            if( numDays <= days ){
                res = min(res, currWeight);
                R = currWeight - 1;
            }
            else{
                L = currWeight + 1;
            }

        }


        return res;
    }
};