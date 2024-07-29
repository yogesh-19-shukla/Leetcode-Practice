class Solution {
    private:
    void f(vector<int>& candidates, int target,int ind,vector<vector<int>> &res,vector<int>&tmp)
    {
        
        if(target==0){
            res.push_back(tmp);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(candidates[i]>target)  break;
            if(i>ind && candidates[i]==candidates[i-1])  continue;
            tmp.push_back(candidates[i]);
            f(candidates,target-candidates[i],i+1,res,tmp);
            tmp.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>tmp;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        f(candidates,target,0,res,tmp);
        return res;
    }
};