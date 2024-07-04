class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        for(auto it : mp){
            if(it.second>n/2)    return it.first;
        }
        return -1;
    }
};