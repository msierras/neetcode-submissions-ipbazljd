class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int L = 0;
        int R = matrix[0].size() - 1;
        
        for(const auto &currRow : matrix){

            while(L <= R){
                int mid = (L + R) / 2;

                if( currRow[mid] < target ){
                    L = mid + 1;
                }   
                else if( currRow[mid] > target ){
                    R = mid - 1;
                }
                else{
                    return true;
                }

            }

            L = 0;
        }

        return false;
    }
};
