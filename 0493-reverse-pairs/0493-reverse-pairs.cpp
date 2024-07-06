class Solution {    
private:
    int mergesort(vector<int>& nums,int low,int high)
    {
        int cnt = 0;
        if(low>=high)  return cnt;
        int mid = (low + high)/2;
        cnt += mergesort(nums,low,mid);
        cnt += mergesort(nums,mid+1,high);
        cnt += countpairs(nums,low,high,mid);
        merge(nums,low,high,mid);
        return cnt;
    }  
private:
    int countpairs(vector<int>& nums,int low,int high,int mid)
    {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
          while (right <= high && nums[i] > 2 * (long long)nums[right]) right++;
        cnt += (right - (mid + 1));
        }
    return cnt;
    }
private:
    void merge(vector<int>& nums,int low,int high, int mid)
    {
        vector<int>temp;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
            }
        for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    } 
    }          
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums,0,n-1);
    }
};