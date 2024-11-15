class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>tmp;
        f(nums,tmp,ans,0);
        return ans;
    }

    void f(vector<int>& nums,vector<int>& tmp,vector<vector<int>> &ans,int start)
    {
        ans.push_back(tmp);
        for(int i=start;i<nums.size();i++)
        {
            tmp.push_back(nums[i]);
            f(nums,tmp,ans,i+1);
            tmp.pop_back();
        }
    }
};