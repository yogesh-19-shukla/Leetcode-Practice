class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = 1;
        int maxprod = nums[0];
        for(int i=0;i<n;i++){
            left = (left==0) ? nums[i] : left*nums[i];
            maxprod = max(maxprod,left); 
        }
        for(int i=n-1;i>=0;i--){
            right = (right==0) ? nums[i] : right*nums[i];
            maxprod = max(maxprod,right); 
        }
        return maxprod;
    }
};