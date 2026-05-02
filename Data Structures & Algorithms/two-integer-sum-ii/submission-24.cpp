class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // Pointers
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right){
            int sum = numbers[left] + numbers[right];   // Having a sum here saves us the operation of calculating it each time at the if and else if statements 
            
            // Checking if sum equals target first saves operation time 
            if( sum == target ){
                return {left+1, right+1};   // Adding 1 to left and right since we want them 1-indexed
            }
            else if( sum > target ){
                right--;
            }
            else{   // When sum < target 
                left++;
            }

        }

        // In the case that no elements are found sum up to target
        return {};

    }
};
