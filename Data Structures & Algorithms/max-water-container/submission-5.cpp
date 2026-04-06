class Solution {
public:
    int maxArea(vector<int>& heights) {
        // int i = 0, j = heights.size() - 1, maxA = 0;

        // for(i = 0; i < heights.size(); i++){
        //         if( ((j - i) * min(heights[i], heights[j])) > maxA ) {
        //             maxA = ((j - i) * min(heights[i], heights[j]));
        //         }
        //         // else if(heights[i] < heights[j]){
        //         //     continue;
        //         // }
        //         else if(heights[j] < heights[i]){
        //             j--;
        //         }
        // }

        int L=0, R=heights.size()-1, maxA=0;

        while(L < R){
            if( ((R - L) * min(heights[L], heights[R])) > maxA){
                maxA = ((R - L) * min(heights[L], heights[R]));
            }
            else if(heights[L] <= heights[R]){
                L++;
            }
            else if(heights[R] <= heights[L]){
                R--;
            }
        }


        return maxA;

    }
};
