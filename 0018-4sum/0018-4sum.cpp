class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1])  continue;
            for(int j=i+1;j<n;j++){
             if(j>i+1 and nums[j]==nums[j-1])  continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum>target)  l--;
                else if(sum<target)  k++;
                else {
                   vector<int> tmp = {nums[i],nums[j],nums[k],nums[l]};
                   ans.push_back(tmp);
                   k++;
                   l--;
                   while(k<l and nums[k]==nums[k-1])  k++;
                   while(k<l and nums[l+1]==nums[l])  l--;
                }
            }
            }
        }
        return ans;
    }
};