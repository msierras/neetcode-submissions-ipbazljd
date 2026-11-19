class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // Want to find a BPH where we can eat all the bananas within h hours
        // Can start with a lower bound from 1 to an upper bound of the max value in the piles vector

        int L = 1;
        int R = *max_element( piles.begin(), piles.end() );
        int ans = R;

        while( L <= R ){

            int k = (L + R) / 2;

            long long numHours = 0;
            for( int i = 0; i < piles.size(); i++ ){
                numHours += ceil(static_cast<double>(piles[i])/k);
            }

            if( numHours > h ){
                L = k + 1;
            }
            else{
                ans = min(ans,k);
                R = k - 1;
            }



        }

        return ans;


    }
};
