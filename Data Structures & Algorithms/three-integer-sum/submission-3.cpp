class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // res will contain our result 
        vector< vector<int> > res; 
        // sorting the nums vector 
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]){    // when i != 0 we check if the current number is equal to previous number, if true we continue since we don't want duplicates 
                continue;
            }

            // creation of left and right pointer for two pointer DSA
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    res.push_back( { nums[i], nums[left], nums[right] } );
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
        
                }
                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }
                else if(nums[i] + nums[left] + nums[right] > 0){
                    right--; 
                }
            }
        }

        return res;


    }
};
