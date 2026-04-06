class Solution {
    public int removeElement(int[] nums, int val) {
        // Will keep track of how many values in nums are not equal to val
        int k = 0;

        for(int i = 0; i < nums.length; i++){
            // Instead of looking for where nums[i] == val we look for where nums[i] != val
            if(nums[i] != val){
                // Set nums[k] equal to value (nums[i]) which is not equal to val
                nums[k] = nums[i]; 
                k++;
            }

        }

        return k;
    }
}