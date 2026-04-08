class Solution {
public:
    void sortColors(vector<int>& nums) {
        // We have only 3 possible values: 0, 1, 2
        // Create a count array where:
        // index 0 → count of 0s
        // index 1 → count of 1s
        // index 2 → count of 2s
        vector<int> colorOccur(3, 0);

        // Count how many times each number appears in nums
        for (const auto& num : nums) {
            colorOccur[num]++;   // Increment the count for that number
        }

        // index will track where we are placing values back into nums
        int index = 0; 

        // Rebuild the nums array in sorted order using the counts
        for (int i = 0; i < 3; i++) {
            // While there are still occurrences of number i left
            while (colorOccur[i] > 0) {
                // Place i into the current position of nums
                nums[index] = i;

                // Decrease count since we used one occurrence
                colorOccur[i]--;

                // Move to the next position in nums
                index++;
            }
        }
    }
};