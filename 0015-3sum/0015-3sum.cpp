class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1])  continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum>0)  k--;
                else if(sum<0)  j++;
                else {
                   vector<int> tmp = {nums[i],nums[j],nums[k]};
                   ans.push_back(tmp);
                   j++;
                   k--;
                   while(j<k and nums[j]==nums[j-1])  j++;
                   while(j<k and nums[k+1]==nums[k])  k--;
                }
            }
        }
        return ans;
    }
};