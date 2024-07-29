class Solution {
private:
    void f(vector<int>& candidates, int target, int ind,vector<vector<int>>&res,vector<int>&temp)
    {
        if(ind>=candidates.size()||target<0)  return;
        if(target==0)  {
            res.push_back(temp);
            return;
        }
        temp.push_back(candidates[ind]);
        f(candidates,target-candidates[ind],ind,res,temp);
        temp.pop_back();
        f(candidates,target,ind+1,res,temp);
    }    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>temp;
        f(candidates,target,0,res,temp);
        return res;
    }
};