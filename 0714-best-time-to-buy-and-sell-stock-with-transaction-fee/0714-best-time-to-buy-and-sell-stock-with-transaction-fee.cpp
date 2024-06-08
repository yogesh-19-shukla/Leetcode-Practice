class Solution {
private:
  int f(int n, vector<int>& prices, int ind, int buy, vector<vector<int>>&dp,int fee)
    {
        //if we have exhausted array we return 0
        if(ind==n)  return 0;
        int profit = 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        // max of either we buy first and cannot buy again
        //or we don't buy first and move to other index for buy
        if(buy){
           profit = max(-prices[ind] + f(n,prices,ind+1,0,dp,fee), 0 + f(n,prices,ind+1,1,dp,fee));
        }
        // max of either we sell and can buy again 
        //or we dont sell and move ahead but can't buy again
        else{
           profit = max(prices[ind] - fee + f(n,prices,ind+1,1,dp,fee), 0 + f(n,prices,ind+1,0,dp,fee));
        }
        return dp[ind][buy] =  profit;
    }    

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));     // buy can take 2 values - 0/1
        return f(n,prices,0,1,dp,fee);

    }
};