class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>tmp;
        sort(nums.begin(),nums.end());
        f(nums,tmp,ans,0);
        return ans;
    }

    void f(vector<int>& nums,vector<int>& tmp,vector<vector<int>> &ans,int start)
    {
        ans.push_back(tmp);
        for(int i=start;i<nums.size();i++)
        {
            if(i>start && nums[i]==nums[i-1])   continue;
            tmp.push_back(nums[i]);
            f(nums,tmp,ans,i+1);
            tmp.pop_back();
        }
    }
};