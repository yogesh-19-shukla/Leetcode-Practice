class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(auto i: nums)   total += i;
        if(total%2!=0)    return false;
        total= total/2;
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return f(n-1,total,nums,dp);
    }

    bool f(int ind,int target,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(target==0)  return true;
        if(ind==0)  return (nums[0]==target);
        if(dp[ind][target]!=-1)   return dp[ind][target];
        bool notpick = f(ind-1,target,nums,dp);
        bool pick = false;
        if(nums[ind]<=target)   pick = f(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target] = pick | notpick;
    }
};