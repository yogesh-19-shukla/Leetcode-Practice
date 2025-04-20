class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt_max = 0, index = 0;
        for(int i=0;i<n;i++){
            sort(mat[i].begin(),mat[i].end());
            int cnt_ones = m - lower(mat[i],m,1);
            if(cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }
    return {index,cnt_max};
    }

    int lower(vector<int> arr, int n, int val)
    {
        int l =0, high = n-1, ans = n;
        while(l<=high){
            int mid = l + (high-l)/2;
            if(arr[mid]>=val)   {ans = mid; high = mid-1;}
            else l = mid+1;
        } 
        return ans;
    }
};