class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0;
        int currSum = 0;
        int res = INT_MAX;

        for(int right = 0; right < nums.size(); right++){
            currSum += nums[right];

            while( currSum >= target ){
                res = min( right - left + 1 , res);
                currSum -= nums[left];
                left++;

            }
        }

        return (res == INT_MAX) ? 0 : res;
    }
};