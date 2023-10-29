class Solution {
public:
    int countVowelPermutation(int n) {
        const int mod=1e9+7;
        const int A=0,E=1,I=2,O=3,U=4;

        vector<vector<long long>> m(n+1,vector<long long>(5,1));

        for(int i=2;i<=n;i++){
            m[i][A] = (m[i - 1][E] + m[i - 1][I] + m[i - 1][U]) % mod;
            m[i][E] = (m[i - 1][A] + m[i - 1][I]) % mod;
            m[i][I] = (m[i - 1][E] + m[i - 1][O]) % mod;
            m[i][O] = m[i - 1][I];
            m[i][U] = (m[i - 1][I] + m[i - 1][O]) % mod;
        } 
         return (m[n][A] + m[n][E] + m[n][I] + m[n][O] + m[n][U]) % mod;  
    }

};