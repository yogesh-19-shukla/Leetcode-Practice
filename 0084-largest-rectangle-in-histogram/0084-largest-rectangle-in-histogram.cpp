class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            int start = i;
            while(!st.empty() && st.top().second > heights[i])
            {
               int index = st.top().first;
               int width = i - index;
               int height = st.top().second;
               st.pop();
               ans = max(ans,height*width);
               start = index;
            }
            st.push({start,heights[i]});
        }
        while(!st.empty())
        {
            int width = n - st.top().first;
            int height = st.top().second;
            st.pop();
            ans = max(ans,height*width);

        }
        return ans;
    }
};