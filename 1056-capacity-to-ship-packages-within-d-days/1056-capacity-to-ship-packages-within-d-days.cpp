class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = INT_MIN, sum = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,weights[i]);
            sum += weights[i]; 
        }
        int low = maxi, high = sum;
        while(low<=high){
            int mid = low + (high-low)/2;
            int ans = func(weights,mid);
            if(ans<=days)   high = mid -1;
            else low = mid + 1;
        }
        return low;
    }

    int func(vector<int>& weights, int capacity)
    {
        int d = 1, load = 0;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i] > capacity){
                d++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return d;
    }
};