class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            high = max(high,piles[i]);
        }
        int ans = high;
        // l = 1 , h = 11
        while(low<=high){
            int mid = low + (high-low)/2;
            long long hours = 0;
            for(int i=0;i<n;i++){
                hours += ceil((double)piles[i]/mid);
            }
            cout<<hours<<endl;
                if(hours <= h){
                    ans = min(ans,mid);
                    high = mid -1;
                }
                else {
                    low = mid + 1;
                }
            
        }
        return ans;
    }
};