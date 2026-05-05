class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;

        // Since num at index 0 is unique by default
        int index = 1; 

        while(left < right){


            if(nums[left] != nums[left + 1]){
                nums[index] = nums[left + 1];
                index++;
            }

            left++;

        }

        return index;

    }
};