class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0;
        long long r = floor(sqrt(c));
        while(l<=r){
            long long sum = l*l + r*r;
            if(sum<c)  l++;
            else if(sum>c)  r--;
            else return true;
        }
        return false;
    }
};