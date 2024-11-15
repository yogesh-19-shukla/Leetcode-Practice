class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>tmp;
        f(k,n,ans,tmp,1);
        return ans;
    }

    void f(int k, int n,vector<vector<int>> &ans,vector<int>&tmp,int start)
    {
        if(n<0 || tmp.size()>k)  return;
        if(tmp.size()==k && n==0)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=start;i<=9;i++)
        {
            tmp.push_back(i);
            f(k,n-i,ans,tmp,i+1);
            tmp.pop_back();
        }
    }
};