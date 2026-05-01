class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;  // Pointing to the last position in nums1
        int i = m - 1;         // Pointing to the last valid element of nums1
        int j = n - 1;         // Pointing to the last element of nums2

        while (j >= 0) {  // Keep going until all elements of nums2 have been placed
            if (i >= 0 && nums1[i] > nums2[j]) {  // i >= 0 guards against going out of bounds; place nums1[i] if it's larger
                nums1[last] = nums1[i];
                last--;
                i--;
            } else {  // nums2[j] is greater than or equal to nums1[i], so place nums2[j]
                nums1[last] = nums2[j];
                last--;
                j--;
            }
        }
    }
};