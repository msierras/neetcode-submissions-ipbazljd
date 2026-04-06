class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int temperatures_size = temperatures.size();

        vector<int> res(temperatures_size, 0);
        stack<int> indices;

        for(int i = 0; i < temperatures_size; i++){
            while(!(indices.empty()) && temperatures[i] > temperatures[indices.top()]){
                res[indices.top()] = i - indices.top();
                indices.pop();
            }

            indices.push(i);
        }


        return res; 
    }
};
