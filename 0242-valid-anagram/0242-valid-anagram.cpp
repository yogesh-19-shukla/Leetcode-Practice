class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        int n = s.length();
        int m = t.length();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int i=0;i<25;i++){
            if(count[i]!=0)  return false;
        }
        return true;
    }
};