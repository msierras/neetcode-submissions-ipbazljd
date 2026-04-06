class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool col[9][9] = { false };
        bool row[9][9] = { false };
        bool box[9][9] = { false };

        
        for(int i = 0; i < 9; i++){ 
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.' ) continue;   // if current position is a '.' character then we skip it since we don't need it.

                int number = board[i][j] - '0' - 1;
                int boxIndex = ( (i/3) * 3 ) + (j/3);

                if( col[i][number] || row[j][number] || box[boxIndex][number] ){
                        return false; 
                    } 

                col[i][number] = true;
                row[j][number] = true; 
                box[boxIndex][number] = true;
            }
        }

        return true;



    }
};
