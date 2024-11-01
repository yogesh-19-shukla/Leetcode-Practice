class Solution {
public:
    bool isEqual(vector<int>v1,vector<int>v2){
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i])  return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n>m)  return false;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(auto it: s1)   v1[it-'a']++;
        int i =0;
        int j=0;
        while(j<m){
            v2[s2[j]-'a']++;
            
            if(j-i+1==n){
                if(isEqual(v1,v2))   return true;
            }
            if(j-i+1<n)  j++;
            else{
                v2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};