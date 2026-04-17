class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size(); 

        
        unordered_map<int, int> hm; 

        // Get number of occurrence for each number in nums
        for(const auto &num : nums) hm[num]++;


        vector<int> res;

        for(const auto &x : hm){
            if(x.second > (n/3) ) res.push_back(x.first);
        }

        return res; 
    }
};