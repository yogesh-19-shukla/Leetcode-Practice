class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, res = 0;
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
           sum += nums[i];
           if(mpp.find(sum-goal)!=mpp.end()){
               res += mpp[sum-goal];
           }
           mpp[sum]++;
           
        }
        return res;
    }
};