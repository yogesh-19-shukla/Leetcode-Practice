class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        //find the break point 
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1]){
                ind = i;    
                break;
            }
        }

        // if no break point 
        if(ind == -1){
            reverse(nums.begin(),nums.end());    
        }
        //if break point exist swap and reverse right hand of array

      else{
         for(int i = n-1;i>=ind;i--){
           if(nums[i] > nums[ind]){
            swap(nums[i],nums[ind]);
            break;
           }
       }
       reverse(nums.begin() + ind + 1,nums.end());
      }
      
    }
};