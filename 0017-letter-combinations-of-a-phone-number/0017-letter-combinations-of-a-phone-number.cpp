class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)  return {};
        unordered_map<char,string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string curr = "";
        vector<string>res;
        dfs(mp,0,curr,res,digits);
        return res;
    }

    void dfs(unordered_map<char,string> &mp,int ind,string &curr,vector<string>&res,string &digits)
    {
        if(ind==digits.size()){
            res.push_back(curr);
            return;
        }

        string str = mp[digits[ind]];
        for(int i=0;i<str.size();i++){
            curr.push_back(str[i]);
            dfs(mp,ind+1,curr,res,digits);
            curr.pop_back();
        }
    }
};