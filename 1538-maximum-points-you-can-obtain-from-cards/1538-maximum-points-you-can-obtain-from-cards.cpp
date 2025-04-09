class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, maxi = 0;
        int n  = cardPoints.size();
        int rind = n-1;
        for(int i=0;i<k;i++)   lsum += cardPoints[i];
        maxi = lsum;
        for(int i=k-1;i>=0;i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rind];
            maxi = max(maxi, lsum + rsum);
            rind--;
        }
        return maxi;
    }
};