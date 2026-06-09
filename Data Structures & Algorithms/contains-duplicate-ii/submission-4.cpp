class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int left = 0;
        unordered_set<int> set;

        for(int right = 0; right < nums.size(); right++){

            if( right - left > k ){
                set.erase(nums[left]);
                left++;
            }

            if( set.contains( nums[right] ) ){
                return true;
            }

            set.insert( nums[right] );
        }

        return false;

    }
};