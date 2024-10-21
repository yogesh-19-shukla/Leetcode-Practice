class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        backtrack(n,0,0,"",res);
        return res;
    }

    void backtrack(int n, int open,int close, string ans, vector<string>&res){
        if(open==n && close==n){
            res.push_back(ans);
        }
        if(open<n){
           backtrack(n,open+1,close,ans+'(',res);
        }
        if(close<open){
            backtrack(n,open,close+1,ans+')',res);
        }
    }
};