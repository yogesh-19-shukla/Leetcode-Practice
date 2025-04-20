class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int maxrow = func(mat,n,m,mid);
            int left = mid-1>=0 ? mat[maxrow][mid-1] : -1;
            int right = mid+1<m ? mat[maxrow][mid+1] : -1;
            if(mat[maxrow][mid]> left && mat[maxrow][mid]> right)   return {maxrow,mid};
            else if(mat[maxrow][mid]<left)  high = mid-1;
            else low = mid + 1;
        }
        return {-1,-1};
    }

    int func(vector<vector<int>>& mat, int n, int m, int col)
    {
        int index = -1, maxval = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col] > maxval){
                maxval = mat[i][col];
                index = i;
            }
        }
        return index;
    }
};