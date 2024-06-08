class Solution {
private:
    int f(int ind, int buy, vector<int>& prices, int n,
          vector<vector<vector<int>>>& dp,int k) {
        if (ind == n || k == 0)
            return 0;
        int profit = 0;
        if (dp[ind][buy][k] != -1)
            return dp[ind][buy][k];
        if (buy) {
            return dp[ind][buy][k] =
                       max(-prices[ind] + f(ind + 1, 0, prices, n, dp,k),
                           0 + f(ind + 1, 1, prices, n, dp,k));
        } else {
            return dp[ind][buy][k] =
                       max(prices[ind] + f(ind + 1, 1, prices, n, dp,k-1),
                           0 + f(ind + 1, 0,prices, n, dp,k));
        }
        return dp[ind][buy][k] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // 2 = buy values (0/1)
        // 3 = cap values (0/1/2)
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 1, prices, n, dp,k);
    }
};