class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // we will use BFS because in 1 unit time it will take care of same level elements
        //here DFS will not work 
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
       // will store as {{row,col},time} at t=0 so initially queue is all filled 
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else {
                    vis[i][j] = 0;
                }
            }
        }
        // now we run our BFS 
int delrow[] = {-1,0,+1,0};
             int delcol[] = {0,-1,0,+1};
             int tm =0;
        while(!q.empty()){
             
             int r = q.front().first.first;
             int c = q.front().first.second;
             int time = q.front().second;
             tm = max(tm,time);
             q.pop();
             for(int i=0;i<4;i++)
             {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1&&vis[nrow][ncol]!=1)
                {
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol] = 1;
                }
             }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]==1)    return -1;
            }
        }
       return tm;
    }
};