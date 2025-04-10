class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }

    int atmost(vector<int>& nums, int k){
        if(k<0)  return 0;
        int i=0,j=0,sum=0,cnt=0;
        while(j<nums.size()){
            sum += (nums[j]%2);
            while(sum>k){
                sum = sum - (nums[i] %2);
                i++;

            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
};