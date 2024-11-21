class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }

    int f(int ind,int x,vector<int>& coins,vector<vector<int>>&dp)
    {
        if(ind==0){
            if(x%coins[0]==0)   return 1;
            return 0;
        }

        if(dp[ind][x]!=-1)   return dp[ind][x];
        int np = f(ind-1,x,coins,dp);
        int p = 0;
        if(coins[ind]<=x){
            p = f(ind,x-coins[ind],coins,dp);
        }
        return dp[ind][x] = np + p;
    }
};