class Solution {
private: 
    void reverse(vector<int> &nums, int left, int right){
        while(left < right){
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size() - 1;
        // Have to modulo k by nums.size() because there's no guarantee that k is less than nums.size()!
        // Problem only guarantees that k is non-negative
        // Normalizes k to a safe range [0, n-1] since rotating by n steps returns the array to its original position, 
        // making any k >= n reducible to its remainder e.g. k=7 on n=5 is equivalent to k=2
        k %= nums.size();

        reverse( nums, 0, n );
        reverse(nums, 0, k - 1);
        reverse(nums, k, n );



    }
};