class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numOccur;
        
        // Populating HashMap numOccur
        for(int i = 0; i < nums.size(); i++){
            numOccur[nums[i]]++;
        }

        int res = 0;
        int len = 0;

        for(const auto& hm : numOccur){
            if(hm.second > len){
                len = hm.second;
                res = hm.first;
            }
        }

        return res;

    }
};