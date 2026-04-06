class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int vector ans will contain the answers that will eventually be returned.
        vector<int> ans;
        // not_i int vector will contain j's that are not equal to i
        vector<int> not_i;

        // outer loop i
        for(int i = 0; i < nums.size(); i++){

            // toReturn int will contain the output of all eleemnts of nums except nums[i]
            int toReturn = 1;

            // inner loop j
            for(int j = 0; j < nums.size(); j++){
                // Checking if the current j element is not equal to the current i element
                // if unequal, add to not_i int vector 
                if(j != i) not_i.push_back( nums[j] ); 
            }

            if( !(not_i.empty()) ){ // if not_i is not empty then we had at least one j that was not equal to i
                for(int k = 0; k < not_i.size(); k++) toReturn *= not_i[k]; 
                ans.push_back(toReturn);
                // clearing not_i because previously I re-declared the not_i vector each time the outer loop iterated
                // this way, we only declare not_i outside of the nested for loop and go from O(n^2) to O(n) space complexity
                not_i.clear();
            }
        }

        return ans;
    }
};
