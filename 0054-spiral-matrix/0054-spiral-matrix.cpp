class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int srow = 0, scol = 0;
        int erow = row-1, ecol = col-1;
        int total = row*col;
        vector<int>ans;
        int cnt = 0;
        while(cnt<total)
        {
            for(int i=scol; cnt<total&& i<=ecol;i++){
                ans.push_back(matrix[srow][i]);
                cnt++;
            }
            srow++;

            for(int i=srow; cnt<total&& i<=erow;i++){
                ans.push_back(matrix[i][ecol]);
                cnt++;
            }
            ecol--;

            for(int i=ecol; cnt<total&& i>=scol;i--){
                ans.push_back(matrix[erow][i]);
                cnt++;
            }
            erow--;
            for(int i=erow; cnt<total&& i>=srow;i--){
                ans.push_back(matrix[i][scol]);
                cnt++;
            }
            scol++;
        }
        return ans;
    }
};