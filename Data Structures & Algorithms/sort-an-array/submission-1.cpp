class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int i = 0;
        int j;

        while(i < nums.size()){
            int j = i + 1;
            while(j < nums.size()){
                if(nums[j] < nums[i]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
                j++;

            }
            i++;
        }
        

        return nums; 
    }
};