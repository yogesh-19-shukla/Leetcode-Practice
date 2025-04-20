class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n)  return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(func(nums,k,n,mid)>k)   low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }

    int func(vector<int>& nums, int k, int n, int maxsum)
    {
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(nums[i]+sum <= maxsum){
                sum += nums[i];
            }else {
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }
};