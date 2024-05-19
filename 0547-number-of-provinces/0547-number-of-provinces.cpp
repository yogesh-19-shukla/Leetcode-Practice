class Solution {
private:
    void dfs(int node,vector<int>adj[], vector<int>&vis) 
    {
        vis[node] = 1;
        for(auto i:adj[node])
        {
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }   
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //change it into adj list
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
           if(!vis[i]){
            ans++;
            dfs(i,adj,vis);
           }
        }
        return ans;
    }
};