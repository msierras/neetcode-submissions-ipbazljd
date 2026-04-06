class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool col[9][9] = { false };
        bool row[9][9] = { false };
        bool box[9][9] = { false };

        
        for(int i = 0; i < 9; i++){ 
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.' ) continue;   // if current position is a '.' character then we skip it since we don't need it.

                int number = board[i][j] - '0' - 1; // transforms '1' - '9' characters into 0 - 8 integers.
                int boxIndex = ( (i/3) * 3 ) + (j/3);   // this formulat tells us which 3x3 box we're currently in, i.e. boxes 0 - 8

                if( col[i][number] || row[j][number] || box[boxIndex][number] ){    // if any of these are true we return false because we dont want repeating numbers!
                        return false; 
                    } 

                // set to true to show that we've seen number here 
                col[i][number] = true;
                row[j][number] = true; 
                box[boxIndex][number] = true;
            }
        }

        // if false was never returned then sudoku board is valid!
        return true;



    }
};
