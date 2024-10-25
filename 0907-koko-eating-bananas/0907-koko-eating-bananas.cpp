class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        for(int i=0;i<piles.size();i++){
          high = max(high,piles[i]);
        }
        int low = 1;
        int res = high;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            long long hours = 0;
            for(int i=0;i<piles.size();i++){
                 hours += ceil((double)piles[i]/mid);
            }
            if(hours<=h){
                res = min(res,mid);
                high = mid - 1;
            }
            else  low = mid + 1;
        }
        return res;
    }
};