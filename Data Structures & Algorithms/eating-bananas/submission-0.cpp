class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Lower bound for binary search is 1 since we're only dealing with positive integers
        int l = 1;

        // Upper bound for binary search is the maximum element in the piles vector
        int r = *max_element(piles.begin(), piles.end());

        int res = r;

        while (l <= r) {

            // k is bananas per hour or BPH
            int k = (l + r) / 2;

            long long totalTime = 0;
            // Getting how long it takes to eat the bananas from each pile at a rate of k
            for (int p : piles) {
                totalTime += ceil(static_cast<double>(p) / k);
            }
            if (totalTime <= h) {   // Is a valid k, so we set res equal to. upper boundary is lowered to see if we can find a smaller k
                res = k;
                r = k - 1;
            } else {    // k is too low, so we increase lower bound
                l = k + 1;
            }
        }
        return res;
    }
};