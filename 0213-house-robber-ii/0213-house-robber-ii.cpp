class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)  return 0;
        if(n==1)  return nums[0];
        int ans1 = f(nums,0,n-2);
        int ans2 = f(nums,1,n-1);
        return max(ans1,ans2);
    }

    int f(vector<int>& nums,int start,int end)
    {
        int prev = 0;
        int curr = 0;
        int next = 0;
        for(int i=start;i<=end;i++)
        {
            next = max(prev+nums[i],curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};