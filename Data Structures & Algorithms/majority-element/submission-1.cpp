class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // HashMap numOccur that will store element frequencies 
        unordered_map<int, int> numOccur;
        
        // Populating HashMap numOccur with element frequencies
        for(int i = 0; i < nums.size(); i++){
            numOccur[nums[i]]++;
        }

        int res = 0;
        int maxCount = 0;

        for(const auto& hm : numOccur){
            /* If the value of the current HashMap key is greater than the 
               greatest known value in the HashMap */
            if(hm.second > maxCount){
                maxCount = hm.second;
                res = hm.first;
            }
        }

        return res;

    }
};