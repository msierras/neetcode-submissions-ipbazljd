class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Initialize pointers
        int last = m + n - 1;   // Initially pointing to last element of nums1
        int i = m - 1; // Initially pointing to last non-zero element in nums1
        int j = n - 1; // Initially pointing to last element in nums2 

        // Once all elements from nums2 are placed, the remaining elements of nums 1 are already in their correct positions. So we only need to loop while j>=0
        while (j >= 0) { 
            if (i >= 0 && nums1[i] > nums2[j]) { 
                nums1[last--] = nums1[i--];
            } else {
                nums1[last--] = nums2[j--];
            }
        }
    }
};