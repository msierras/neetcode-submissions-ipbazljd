class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // initialization of vector ans which will contain our indices
        vector<int> ans;
        // double for loop used to search for the indices that add up to target.
        // j = i + 1 since we're not allowed to use the same element twice. 
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        
        // in the case that no pair is found we return an empty vector to avoid errors.
        return {};
    }
};
