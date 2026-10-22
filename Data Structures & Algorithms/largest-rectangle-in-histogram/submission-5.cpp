class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> indices;
        int maxArea = 0;

        int n = heights.size();

        for(int i = 0; i <= n; i++){

            while( !indices.empty() && ( i == n || heights[i] < heights[indices.top()] ) ){
                
                int height = heights[indices.top()];
                indices.pop();

                int width = ( indices.empty() ) ? i : i - indices.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            indices.push(i);
        }



        return maxArea;

    }
};
