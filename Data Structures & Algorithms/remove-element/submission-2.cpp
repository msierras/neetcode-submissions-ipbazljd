class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int numTimes; 
        vector<int> temp; 

        for(int i =0; i < nums.size(); i++){
            if(nums[i] != val){
                temp.push_back(nums[i]);
                numTimes++;
            }
        }
        nums = temp;
        return numTimes;
    }
};