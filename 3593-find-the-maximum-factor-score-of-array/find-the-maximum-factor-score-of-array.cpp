class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return (long long)nums[0] * nums[0]; // Single element case
        
        // Calculate prefix and suffix GCD arrays
        vector<int> prefixGCD(n), suffixGCD(n);
        prefixGCD[0] = nums[0];
        suffixGCD[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; ++i) {
            prefixGCD[i] = gcd(prefixGCD[i - 1], nums[i]);
        }
        
        for (int i = n - 2; i >= 0; --i) {
            suffixGCD[i] = gcd(suffixGCD[i + 1], nums[i]);
        }
        
        // Calculate the initial LCM and GCD for the entire array
        long long initialLCM = nums[0];
        for (int i = 1; i < n; ++i) {
            initialLCM = lcm(initialLCM, (long long)nums[i]);
        }
        long long maxScore = initialLCM * prefixGCD[n - 1]; // Score without removing any element
        
        // Try removing each element and calculate the max factor score
        for (int i = 0; i < n; ++i) {
            int gcdWithoutI = 0;
            if (i == 0) {
                gcdWithoutI = suffixGCD[1];
            } else if (i == n - 1) {
                gcdWithoutI = prefixGCD[n - 2];
            } else {
                gcdWithoutI = gcd(prefixGCD[i - 1], suffixGCD[i + 1]);
            }
            
            // Calculate LCM without the ith element
            long long lcmWithoutI = 1;
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                lcmWithoutI = lcm(lcmWithoutI, (long long)nums[j]);
            }
            
            // Update max score
            maxScore = max(maxScore, gcdWithoutI * lcmWithoutI);
        }
        
        return maxScore;
    }
    
private:
    // Helper function to calculate LCM of two numbers
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
};