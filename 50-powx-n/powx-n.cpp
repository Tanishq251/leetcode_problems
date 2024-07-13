class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long a = n;
        if (a < 0) {
            a = -a;
        }
        while (a) {
            if (a % 2) {
                res *= x;
                a -= 1;
            } else {
                x *= x;
                a /= 2;
            }
        }
        if (n < 0) {
            res = 1 / res;
        }
        return res;
    }
};