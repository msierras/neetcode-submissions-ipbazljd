class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        /*  
            We want, for every bar, to know how wide it can stretch while being the shortest bar in that rectangle
            
            A monotonic stack helps with this:
            - We keep a stack of INDICES where the bar heights are in increasing order
            - As long as the next bar is taller or equal, we keep pushing indices
            - When we see a shorter bar, it means the bar on top of the stack can't extend further to the right
                - We pop the bar on top of the stack and treat it as the height of a rectangle
                - Its width goes from the new top of the stack + 1 up to the current index - 1

            To make sure every bar eventually gets popped and processed, we run the loop one extra step with a "virtual" bar
            of height 0 at the end        
        */


        int n = heights.size();
        int maxArea = 0;    // Initially set to 0 because heights[i] can only ever be 0 <= heights[i] <= 10,000
        stack<int> stack;

        for (int i = 0; i <= n; i++) {

            // Make sure that stack is not empty since popping an empty stack will result in an error
            // AND
            // i==n occurrs when we're one past the last bar, this is to flush out uncalculated bars. An example could be where each bar is bigger than the last.
            // OR
            // 
            while (!stack.empty() && (i == n || heights[i] < heights[stack.top()])) {
                int height = heights[stack.top()];  // stack keeps the indices of the bars
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stack.push(i);
        }
        return maxArea;
    }
};