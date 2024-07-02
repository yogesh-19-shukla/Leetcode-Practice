class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int least = prices[0];
        int maxi = 0 , today = 0;
        for(int i=1;i<n;i++){
            if(prices[i] < least) least = prices[i];
            today = prices[i] - least;
            maxi = max(maxi,today);
        }
        return maxi;
    }
};