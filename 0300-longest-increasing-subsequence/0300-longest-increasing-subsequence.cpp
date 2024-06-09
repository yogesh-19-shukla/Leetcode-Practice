class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>tmp;
        tmp.push_back(nums[0]);
        int len = 1;
        for(int i=1;i<n;i++){
            if(nums[i] > tmp.back()){
                tmp.push_back(nums[i]);
                len++;
            }
            else {
                //this will give the index at which we will replace the value of curr nums[i]
                int ind = lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin();
                tmp[ind] = nums[i];
            }
        }
        return len;
    }
};