class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int maxArea = 0;

        int L = 0;
        int R = heights.size() - 1;

        while(L < R){
            int currArea = (R - L) * min(heights[L], heights[R]);

            if( currArea > maxArea) maxArea=currArea; 
            
            // The maximum height depends on the shortest column
            // We need to go inward to try and find taller columns
            // Can say that the shorter column causes water to "splil"
            if( heights[L] < heights[R] ) L++;
            else R--;
        }

        return maxArea; 

    }
};
