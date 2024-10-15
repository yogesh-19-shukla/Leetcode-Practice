class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)  mp[nums[i]]++;
        vector<vector<int>>bucket(n+1);
        for(auto it:mp){
            bucket[it.second].push_back(it.first);
        }
        for(int i=n;i>=0;i--){
            if(ans.size()>=k)  break;
            if(!bucket.empty()){
                ans.insert(ans.end(),bucket[i].begin(),bucket[i].end());
            }
        }
        return ans;
    }
};