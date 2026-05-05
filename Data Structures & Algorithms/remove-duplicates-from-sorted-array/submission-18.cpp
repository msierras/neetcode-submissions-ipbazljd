class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // left pointer also serves as num of unique numbers
        // starting at 1 since first element of nums is unique by default
        int left = 1;
        
        for (int right = 1; right < nums.size(); right++) {
            if (nums[right] != nums[right - 1]) {
                nums[left] = nums[right];
                left++;
            }
        }

        return left;
    }
};