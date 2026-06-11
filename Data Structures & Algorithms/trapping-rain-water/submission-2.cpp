class Solution {
public:
    int trap(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;
        
        int leftMax = height[left];
        int rightMax = height[right];
        
        int res = 0;




        while( left < right ){

            if( height[left] < height[right] ){
                left++;
                leftMax = max(height[left], leftMax);
                res += leftMax - height[left];
            }
            else{
                right--;
                rightMax = max(height[right], rightMax);        
                res += rightMax - height[right];
            }


        }

        return res; 

    }
};
