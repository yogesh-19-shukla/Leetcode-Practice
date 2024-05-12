class Solution {
public:
    double myPow(double x, int n) {
        long exponent = abs(n);
        double result = 1.0;
        
        for (long i = exponent; i > 0; i /= 2) {
            if (i % 2 == 1) {
                result *= x;
            }
            x *= x;
        }
        
        if (n < 0) {
            return 1.0 / result;
        }
        return result;
    }
};