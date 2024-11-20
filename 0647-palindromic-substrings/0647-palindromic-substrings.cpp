class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            f(i,i,s,res);
            f(i,i+1,s,res);
        }
        return res;
    }

    void f(int i,int j,string s,int &res)
    {
        while(i>=0 && j<s.length() && s[i]==s[j]){
            res++;
            i--;
            j++;
        }
    }
};