class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right){
            int sum = numbers[left] + numbers[right];   // Having a sum here saves us the operation of calculating it each time at the if and else if statements 
            if( sum > target ){
                right--;
            }
            else if( sum < target ){
                left++;
            }
            else{
                return {left+1, right+1};   // Adding 1 to left and right since we want them 1-indexed
            }


        }

        return {};

    }
};
