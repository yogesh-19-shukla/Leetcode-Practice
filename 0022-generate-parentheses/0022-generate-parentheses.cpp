class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,0,0,"",res);
        return res;
    }
    void generate(int n, int o,int c,string s,vector<string>&res)
    {
        if(o==n && c==n)  res.push_back(s);
        if(o<n)   generate(n,o+1,c,s+'(',res);
        if(c<o)   generate(n,o,c+1,s+')',res);
    }
};