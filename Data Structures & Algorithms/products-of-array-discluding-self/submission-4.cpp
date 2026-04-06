class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> ans;


        for(int i = 0; i < nums.size(); i++){
            vector<int> f_loop;
            int toReturn = 1;

            // Checking if the current j element is not equal to the current i element
            for(int j = 0; j < nums.size(); j++){
                if(j != i){
                   f_loop.push_back(nums[j]); 
                }
            }

            if(!f_loop.empty()){
                for(int k = 0; k < f_loop.size(); k++) toReturn *= f_loop[k]; 
                ans.push_back(toReturn);
            }

            
        }

        return ans;
    }
};
