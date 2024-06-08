// same as buy and sell stocks -2 with an additional parameter as cap.

class Solution {
private:
    int f(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>&dp) {
        if(ind==n || cap==0)  return 0;
        int profit = 0;
        if(dp[ind][buy][cap]!=-1)  return dp[ind][buy][cap];
        if(buy){
           return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1,0,cap,prices,n,dp), 0 + f(ind+1,1,cap,prices,n,dp));
        }
        else{
           return dp[ind][buy][cap] = max(prices[ind] + f(ind+1,1,cap-1,prices,n,dp), 0 + f(ind+1,0,cap,prices,n,dp));
        }
        return dp[ind][buy][cap] =  profit;
    }   
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       // 2 = buy values (0/1)
       // 3 = cap values (0/1/2)
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,n,dp);
    }
};