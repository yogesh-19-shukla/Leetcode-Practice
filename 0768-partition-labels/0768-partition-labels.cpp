class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int>lastindex(26);
        for(int i=0;i<n;i++){
            lastindex[s[i]-'a'] = i;
        }

        int size = 0, end = 0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            size++;
            end = max(end,lastindex[s[i]-'a']);
            if(i==end){
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};