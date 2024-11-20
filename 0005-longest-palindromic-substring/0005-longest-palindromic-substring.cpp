class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(); 
        int start=0;
        int reslen = 1;
        string res = "";
        if(n==0)  return res;
        
       
        for(int i=0;i<n;i++)
        {
             //odd length palindrome
            middleout(s,i,i,start,reslen);
             //even length palindrome
            middleout(s,i,i+1,start,reslen);
        }
        return s.substr(start,reslen);
    }

    void middleout(string s, int i, int j,int& start, int& reslen)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
        }
        if(j-i-1>reslen){
            start = i+1;
            reslen = j-i-1;
        }
    }
};
