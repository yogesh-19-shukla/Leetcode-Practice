class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxcur=0;
        int maxi = 0;
        for(int i=1;i<n;i++){
            maxcur = max(0, maxcur+=prices[i]-prices[i-1]);
            maxi = max(maxi,maxcur);
        }
        return maxi;
    }
};