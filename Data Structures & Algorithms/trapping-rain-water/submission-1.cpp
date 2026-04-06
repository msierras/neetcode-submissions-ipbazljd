class Solution {
public:
    int trap(vector<int>& height) {
        // creation of two pointers
        int left = 0;
        int right = height.size() - 1; 


        // leftMax and rightMax will hold the current highest bar 
        int leftMax = height[left];
        int rightMax = height[right];

        //  res will hold our final result 
        int res = 0;

        while(left < right){
            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                res += leftMax - height[left];
            }
            else{
                right--;
                rightMax = max(rightMax, height[right]);
                res += rightMax - height[right];
            }
        }

        return res; 


    }
};
