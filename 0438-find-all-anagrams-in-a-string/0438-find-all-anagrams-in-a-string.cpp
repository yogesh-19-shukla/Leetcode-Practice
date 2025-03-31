class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(m>n)  return {};
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        vector<int> res;
        for(auto c: p)   v1[c-'a']++;
        for(int i=0;i<m;i++)   v2[s[i]-'a']++;
        if(v1==v2)  res.push_back(0);
        for(int i=m;i<n;i++){
            v2[s[i]-'a']++;
            v2[s[i-m]-'a']--;
            if(v1==v2)   res.push_back(i-m+1);
        }
        return res;
    }
};