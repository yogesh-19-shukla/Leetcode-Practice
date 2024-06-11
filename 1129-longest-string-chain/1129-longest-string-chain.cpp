class Solution {
private:
    bool check(string &s1, string &s2)
    {
        if(s1.size() != s2.size() + 1)    return false;
        int first = 0;    // pointing to bigger string 1st char
        int second = 0;   // pointing to smaller string 1st char
        while(first < s1.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }
            else {
                first++;
            }
        }
        if(first == s1.size() && second == s2.size())   return true;
        return false;
    }
   static bool compa(string &s1, string &s2){
        return s1.size() < s2.size();
    }        
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(),words.end(),compa);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i],words[j]) && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];                   
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
            }
        }
       return maxi;
    }
};