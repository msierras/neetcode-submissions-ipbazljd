class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right){
            
            if( numbers[left] + numbers[right] > target ){
                right--;
            }
            else if( numbers[left] + numbers[right] < target){
                left++;
            }
            else{
                return {left+1, right+1};   // Adding 1 to left and right since we want them 1-indexed
            }


        }

        return {};

    }
};
