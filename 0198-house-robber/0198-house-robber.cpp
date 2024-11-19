class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(nums,dp,n-1);
    }

    int f(vector<int>& nums,vector<int>& dp,int ind)
    {
        if(ind==0)  return nums[0];
        if(ind<0)  return 0;
        if(dp[ind]!=-1)  return dp[ind];
        int pick = nums[ind] + f(nums,dp,ind-2);
        int notpick = f(nums,dp,ind-1);
        return dp[ind] = max(pick,notpick);
         
    }
};