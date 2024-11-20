class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int i=0;i<col;i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                int ld=1e9,rd = 1e9;
                int up = matrix[i][j] + dp[i-1][j];
                if(j-1>=0)  ld = matrix[i][j] + dp[i-1][j-1];
                if(j+1<col) rd = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min(up,min(ld,rd));
            }
        }
        int mini = dp[row-1][0];
        for(int j=0;j<col;j++){
            mini = min(mini,dp[row-1][j]);
        }
        return mini;
    }
};