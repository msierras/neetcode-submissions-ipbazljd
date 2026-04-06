class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Initialization of left and right pointers for two-pointer approach
        int L=0;
        int R=numbers.size()-1;

        // Fulfilling the requirement that index1(L) must be less than index2(R) with the while(L<R)
        while(L < R){
            // if numbers[L]+numbers[R]>target then we decrease index of R since greatest numbers are at the right
            if(numbers[L] + numbers[R] > target){
                R--;
            }
            // if numbers[L]+numbers[R]<target then we increase index of R since smallest numbers are at the left
            else if(numbers[L] + numbers[R] < target){
                L++;
            }
            // only other situation would be where numbers[L]+numbers[R] == target.
            // in this case we increment L and R indexes by 1 since the problem states that the vector starts 1-indexed
            else{
                return {L+1, R+1};
            }
        }

        // in the case that L<R never occurs
        return {};

    }
};
