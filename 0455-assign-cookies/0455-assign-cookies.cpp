class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int i = n-1, j = m-1;
        int ans = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i>=0 && j>=0){
             if(g[i]<=s[j]){
                ans++;
                i--;
                j--;
             }else{
                i--;
             }
        }
        return ans;
    }
};