class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n= s.length();
        for(int i=0;i<n;i++)
        {
            //odd length palindrome
            middleout(s,i,i,res);
            //even length palindrome
            middleout(s,i,i+1,res);
        }
        return res;
    }

    void middleout(string s,int i,int j,int& res)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            res++;
            i--;
            j++;
        }
    }
};