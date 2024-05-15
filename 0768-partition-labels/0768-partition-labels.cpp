/*
1. determine last index of each character
2. make size =0, end =0, vector of res;
3. for each element increase size and update end 
4. if i==end push in res , size =0
TC = O(N)   SC = O(N)
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastindex(26);
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            lastindex[s[i]-'a'] = i;
        }
        int size = 0;
        int end = 0;
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            size++;
            end = max(end,lastindex[s[i]-'a']);
            if(i==end){
                res.push_back(size);
                size=0;
            }
        }
        return res;
    }
};