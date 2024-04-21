class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //make a temp vector
        vector<int>temp;
        vector<vector<int>>result;
        backtrack(nums,0,temp,result);
        return result;
    }

    void backtrack(vector<int>& nums, int start,vector<int>& temp,vector<vector<int>>& result)
    {
        //add temp to result
        result.push_back(temp);
        //now we will either add the element to temp or dont add
        for(int i=start;i<nums.size();i++)
        {
            //adding the element to temp
            temp.push_back(nums[i]);
            //recursively doing for other elements
            backtrack(nums,i+1,temp,result);
            //removing or not adding the element in temp
            temp.pop_back();
        }
    }
};