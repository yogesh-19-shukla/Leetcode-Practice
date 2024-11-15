class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
         vector<int>tmp;
         f(candidates,target,tmp,ans,0);
         return ans;
    }

    void f(vector<int>& candidates, int target,vector<int>& tmp, vector<vector<int>> &ans ,int start)
    {
        if(start>=candidates.size() || target<0)  return;
        if(target==0)
        {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(candidates[start]);
        f(candidates,target-candidates[start],tmp,ans,start);
        tmp.pop_back();
        f(candidates,target,tmp,ans,start+1);

    }
};