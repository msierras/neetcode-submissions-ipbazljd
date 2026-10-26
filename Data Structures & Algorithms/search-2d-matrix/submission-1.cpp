class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(const auto &currRow : matrix){

            int L = 0;
            int R = currRow.size() - 1;

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


        }

        return false;
    }
};
