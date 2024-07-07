class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false; 
        
        int t = 0;  
        for (int i = 0; i < n; ++i) {
            if (i > t) {
                return false; 
            }
            t = max(t, i + nums[i]);  
            if (t >= n - 1) {
                return true; 
            }
        }
        return false; 
    }
};
