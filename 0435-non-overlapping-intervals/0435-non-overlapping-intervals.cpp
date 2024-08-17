bool comp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = -1;
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> temp = intervals[0];
        for (auto it : intervals) {
            if (it[0] < temp[1])
                ans++;
            else
                temp = it;
        }
        return ans;
    }
};