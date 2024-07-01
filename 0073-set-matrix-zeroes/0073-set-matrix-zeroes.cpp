class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col0 = 1;    // this is i=0 j=0 element
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j]==0){
                    //mark the ith row =0
                    matrix[i][0] = 0;
                    //mark jth col as 0
                    if(j!=0)    matrix[0][j] = 0;
                    else col0 = 0;
                }
            }
        }

        //step 2 leave 1st row and 1 col and solve for rest

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]!=0){
                    //check for 1st row and col
                    if(matrix[0][j] == 0 || matrix[i][0] ==0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // step 3 for 1st row and col -- solve row first
        if(matrix[0][0]==0){
            for(int j=0;j<cols;j++)   matrix[0][j] = 0;
        }

        if(col0 == 0){
            for(int i=0;i<rows;i++){
                matrix[i][0] = 0;
            }
        }
    }
};