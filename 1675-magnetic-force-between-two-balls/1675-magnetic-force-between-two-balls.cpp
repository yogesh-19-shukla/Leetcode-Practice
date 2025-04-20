class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        int res = 0;
        sort(position.begin(),position.end());
        int low = 1, high = position[n-1] - position[0];
        while(low<=high){
            int mid = low + (high-low)/2;
            if(func(position,m,mid)){
                res = mid;
                low = mid+1;
            }else high = mid - 1;
        }
        return res;
    }

    bool func(vector<int>& position, int m, int force){
        int cnt = 1, last = position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=force){
                cnt++;
                last = position[i];
                if(cnt==m)   return true;
            }
        }
        return false;
    }
};