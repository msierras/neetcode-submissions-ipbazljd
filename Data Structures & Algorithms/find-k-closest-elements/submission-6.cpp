class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1; 
        
        while(right - left >= k){   
            int a = arr[left];
            int b = arr[right];

            if( abs( a - x ) <= abs(  b - x ) ){ // We use <= to consider the case where a and b are both equally close to x. In that case, a takes precedence over b
                right--;
            }
            else{
                left++;
            }

        }

        return vector<int>(arr.begin() + left, arr.begin() + right + 1);

    }
};