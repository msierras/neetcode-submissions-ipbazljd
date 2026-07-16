class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // We'll create a window of size k
        // At each window we want to return the largest element in it


        vector<int> res;
        vector<int> window;

        for(int right = 0; right < nums.size(); right++){

            window.push_back( nums[right] );

            while( window.size() >= k ){
                res.push_back( *max_element( window.begin(), window.end() ) );
                window.erase( window.begin()  );
            }


        }

        return res;
    }
};
