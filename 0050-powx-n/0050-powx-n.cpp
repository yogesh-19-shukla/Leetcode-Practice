class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long exp = abs(n);
        for(long i=exp;i>0;i/=2){
            if(i%2==1)   {
                res *= x;
            }
            x *= x;
        }

        if(n<0)  return 1.0/res;
        return res;
    }
};