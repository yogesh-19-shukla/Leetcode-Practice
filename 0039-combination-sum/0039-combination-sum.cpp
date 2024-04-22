class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>res;
        backtrack(candidates,target,0,temp,res);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int i,vector<int>& temp,vector<vector<int>>& res )
    {
        if (i >= candidates.size() || target < 0)
            return;

        if (target == 0) {
            res.push_back(temp);
            return;
        }
        temp.push_back(candidates[i]);
        backtrack(candidates,target-candidates[i],i,temp,res);
        temp.pop_back();
        backtrack(candidates,target,i+1,temp,res);

    }
};