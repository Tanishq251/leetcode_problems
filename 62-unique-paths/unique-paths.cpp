class Solution {
public:
    long long uniquePaths(int m, int n) {
        int Numerator = n+m-2;
        int Denominator = m-1;
        double ans = 1;



        for(int i=1;i<=Denominator; i++){
            ans=ans*(Numerator-Denominator+i)/i;
        }
        return (long long)ans;
    }
};