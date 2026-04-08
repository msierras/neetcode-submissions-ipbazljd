class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Want indices 0, 1, 2
        vector<int> colorOccur(3);

        for( const auto& num  : nums){
            colorOccur[num]++;
        }

        int index = 0; 
        for(int i = 0; i < colorOccur.size(); i++){
            while(colorOccur[i] > 0){
                nums[index] = i;
                colorOccur[i]--;
                index++;
            }
        }



    }
};