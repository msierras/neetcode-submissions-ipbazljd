class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = n + m - 1;
        int i = m - 1;
        int j = n - 1;

        while( j >= 0){ 

            if( i >= 0 && nums1[i] > nums2[j] ){    // We need i>=0 or we'd go out of bounds
                nums1[last] = nums1[i];
                last--;
                i--;
            }
            else{
                nums1[last] = nums2[j];
                last--;
                j--;
            }

        }


    }
};