class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)  return x;
        int l = 1, h=x;
        int ans = 1;
        while(l<=h){
            long long mid = l + (h-l)/2;
            if(mid*mid<=x){
                ans = mid;
                l =mid+1;
            }
            else     h = mid-1;
        }
        return ans;
    }
};