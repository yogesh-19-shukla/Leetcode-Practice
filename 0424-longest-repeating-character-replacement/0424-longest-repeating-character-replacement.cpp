class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int res = 0, mf = 0;
        int i=0,j=0;
        int count[26] = {0};
        while(j<n)
        {
          count[s[j]-'A']++;
          mf = max(mf,count[s[j]-'A']);
          if(j-i+1 - mf > k){
            count[s[i]-'A']--;
            mf=0;
            i++;
          }
          else res = max(res,j-i+1);
          j++;
        }
        return res;
    }
};