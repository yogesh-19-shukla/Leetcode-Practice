class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int res = 0;
        sort(nums.begin(),nums.end());
        vector<int>power(n,1);
        for(int i=1;i<n;i++){
            power[i] = (power[i-1]*2)%mod;
        }
        int i= 0, j = n-1;
        while(i<=j){
            int sum = nums[i] + nums[j];
            if(sum<=target){
               res = (res + power[j-i]) % mod;
               i++;

            }else {
                j--;
            }
        }
        return res;
    }
};