class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return max(nums[0],nums[1]);
        int choice1 = robber(nums,0,nums.size()-2);
        int choice2 = robber(nums,1,nums.size()-1);
        return max(choice1,choice2);
    }

    int robber(vector<int>& nums,int i, int j)
    {
        int prev = 0, cur = 0, next = 0;
        for(int k = i; k<=j;k++){
            next = max(prev+nums[k],cur);
            prev = cur;
            cur = next;
        }
        return cur;
    }
};