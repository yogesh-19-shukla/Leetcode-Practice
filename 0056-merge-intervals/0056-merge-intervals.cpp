class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        vector<int>temp = intervals[0];
        for(auto it : intervals){
            if(it[0]<=temp[1]){
                temp[1] = max(it[1],temp[1]);
            }
            else {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};