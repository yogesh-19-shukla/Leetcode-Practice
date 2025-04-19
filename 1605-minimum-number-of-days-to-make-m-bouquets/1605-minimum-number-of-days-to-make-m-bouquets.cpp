class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = INT_MAX, maxi =INT_MIN;
        int n = bloomDay.size();
        long long val = m * 1LL * k * 1LL;
        if(n<val)  return -1;
        for(int i=0;i<n;i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini, high = maxi;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay,mid,m,k)==true){
                high = mid-1;
            }
            else  low = mid+1;
        }
        return low;
    }

    bool possible(vector<int>& bloomDay, int day ,int m, int k)
    {
        int boq = 0, cnt = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            } else{
                boq += cnt/k;
                cnt = 0;
            }
        }
        boq += cnt/k;
        return boq>=m;        
    }
};