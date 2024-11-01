class Solution {
public:
    bool isEqual(vector<int>v1,vector<int>v2){
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i])  return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        if(n<m)  return {};
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        vector<int>res;
        for(auto it: p)   v1[it-'a']++;
        int i =0;
        int j=0;
        while(j<n){
            v2[s[j]-'a']++;
            
            if(j-i+1==m){
                if(isEqual(v1,v2))   res.push_back(i);
            }
            if(j-i+1<m)  j++;
            else{
                v2[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return res;
    }
};
