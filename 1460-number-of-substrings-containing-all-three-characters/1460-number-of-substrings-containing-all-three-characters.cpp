class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>lastseen(3,-1);
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            lastseen[s[i]-'a'] = i;
            cnt += 1 + min(lastseen[0],min(lastseen[1],lastseen[2])); 
        }
        return cnt;
    }
};