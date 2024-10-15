class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(target-numbers[i])!=mp.end()){
                return {mp[target-numbers[i]],i+1};
            }
            mp[numbers[i]] = i+1;
        }
        return {};
    }
};