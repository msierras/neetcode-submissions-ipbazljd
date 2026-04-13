class NumMatrix {
public:
    vector<vector<int>> matrix;

    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;

        for(int upperLeftRow = row1; upperLeftRow <= row2; upperLeftRow++){
            for(int upperLeftColumn = col1; upperLeftColumn <= col2; upperLeftColumn++ ){
                res += matrix[upperLeftRow][upperLeftColumn];
            }
        }

        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */