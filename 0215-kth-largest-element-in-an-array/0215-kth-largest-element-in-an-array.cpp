class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int x = 0;
        while(k>0){
            x = pq.top();
            pq.pop();
            k--;
        }
        return x;
    }
};