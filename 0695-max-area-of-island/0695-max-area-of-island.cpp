class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans = max(ans,dfs(i,j,n,m,grid));
                }
            }
        }
        return ans;
    }

    int dfs(int i,int j, int n,int m, vector<vector<int>>&grid)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1)   return 0;
        grid[i][j] = 0;
        return 1 + dfs(i,j-1,n,m,grid) + dfs(i,j+1,n,m,grid) + dfs(i-1,j,n,m,grid) + dfs(i+1,j,n,m,grid);
        
    }
};