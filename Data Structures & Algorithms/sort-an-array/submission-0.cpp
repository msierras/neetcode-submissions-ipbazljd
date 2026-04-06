class Solution {
private:
    // nums: array to be sorted (passed by reference)
    // n: size of the array
    void shellSort(vector<int>& nums, int n) {
        // Start with a gap of n/2 and reduce it by half each iteration
        // When gap = 1, the algorithm becomes standard insertion sort
        for (int gap = n / 2; gap >= 1; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int tmp = nums[i];  // Store the current element to be inserted into its correct position
                int j = i - gap;    // j starts at the previous element in the current gap sequence
                while (j >= 0 && nums[j] > tmp) {   // Shift elements that are greater than tmp to the right (by gap)
                    nums[j + gap] = nums[j];    // Move nums[j] one gap position to the right
                    j -= gap;   // Move to the previous element in the gap sequence
                }
                // 
                nums[j + gap] = tmp;    // Place tmp in its correct position within the gap-sorted sequence
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        // Arrays with 0 or 1 element are already sorted
        if (nums.size() == 1) return nums;
        
        shellSort(nums, nums.size());
        
        return nums;
    }
};