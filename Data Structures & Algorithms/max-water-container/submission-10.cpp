class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int maxArea = 0;

        int L = 0;
        int R = heights.size() - 1;

        while(L < R){
            int currArea = (R - L) * min(heights[L], heights[R]);

            if( currArea > maxArea) maxArea=currArea; 
            else if( heights[L] < heights[R] ) L++;
            else R--;
        }

        return maxArea; 

    }
};
