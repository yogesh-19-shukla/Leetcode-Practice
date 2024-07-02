class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxcur=prices[0];
        int maxi = 0;
        for(int i=1;i<n;i++){
            maxcur = min(maxcur, prices[i]);
            maxi = max(maxi,prices[i] - maxcur);
        }
        return maxi;
    }
};