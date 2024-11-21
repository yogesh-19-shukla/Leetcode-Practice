class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(coins, amount, n - 1, dp);
        if (ans >= 1e9)
            ans = -1;
        return ans;
    }

    int f(vector<int>& coins, int x, int ind, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (x % coins[0] == 0)
                return x / coins[0];
            return 1e9;
        }
        if (dp[ind][x] != -1)
            return dp[ind][x];
        int nottake = 0 + f(coins, x, ind - 1, dp);
        int take = INT_MAX;
        if (coins[ind] <= x)
            take = 1 + f(coins, x - coins[ind], ind, dp);

        return dp[ind][x] = min(nottake, take);
    }
};